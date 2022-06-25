#include "tcpserver.h"
#include <QJsonDocument>
#include <QJsonObject>

TcpServer::TcpServer(const QHostAddress Hostname, int PortNumber, QString Username, QObject *parent)
    : QObject{parent}, HostIp{Hostname}, Port{PortNumber}, UserCount{1}, ServerUsername{Username.simplified()}
{

    in.setVersion(QDataStream::Qt_6_2);
    tcpServer = new QTcpServer(this);
    // COME BACK TO THE HOST ADDRESS + PORT INPUTS
    if(!tcpServer->listen(QHostAddress::Any,35571))
    {
        qDebug() << "Server Listen Error!";
        qDebug() << tcpServer->errorString();
        return;
    }
    QHostAddress ServerHostAddress = tcpServer->serverAddress();
    QString IpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << tr("Server is running on IP : %1 Port : %2").arg(IpAddress).arg(tcpServer->serverPort());
    connect(tcpServer, &QTcpServer::newConnection, this, &TcpServer::ClientConnected);
}

void TcpServer::MessageClient(ServerMessageTypes MessageType, int ClientId, QString DataToSend, int UserId)
{
//    ClientId = Client you're sending message to
//    UserId = Id of the data you're sending
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(MessageType).toJsonValue()},
        {"Data", DataToSend},
    };
    QTcpSocket* ClientSocket = ClientIndex[ClientId];
    if(MessageType == ServerMessageTypes::GameScoreUpdate)
    {
        object = CreateUsernameScoreJsonObject(DataToSend, ClientId, UserId);

    }
    QJsonDocument jsonDoc{object};
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc.toJson(QJsonDocument::Compact);
    ClientSocket->write(block);
}

void TcpServer::MessageClientData(ServerMessageTypes MessageType, QJsonObject DataToSend, int ClientId)
{
    QTcpSocket* ClientSocket = ClientIndex[ClientId];
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(MessageType).toJsonValue()},
        {"Data", DataToSend},
    };
    QJsonDocument jsonDoc{object};
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc.toJson(QJsonDocument::Compact);
    ClientSocket->write(block);
}

QJsonObject TcpServer::CreateUsernameScoreJsonObject(QString Score, int ClientId, int UserId)
{
    QString ClientUsername = ClientUsernames.find(UserId) == ClientUsernames.end() ? ServerUsername : ClientUsernames[UserId];
    bool ClientState = UserId == 0 ? true : false;
    QJsonObject DataToSend
    {
        {"MessageType", QVariant::fromValue(ServerMessageTypes::GameScoreUpdate).toJsonValue()},
        {"Score", Score},
        {"Username", ClientUsername},
        {"State", ClientState}
    };
    qDebug() << "User : " << ClientUsername << " scored : " << Score;
    return DataToSend;
}

void TcpServer::GetClientUsername(int Score, int ClientId, bool State)
{
    QString Username = ClientUsernames[ClientId];
    emit SendUsernameAndScore(Username, Score, State);
}

void TcpServer::SendNewQuestion(QString newQuestion, int ClientId)
{
    QTcpSocket* ClientSocket = ClientIndex[ClientId];
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(ServerMessageTypes::GameUpdate).toJsonValue()},
        {"Data", newQuestion},
    };
    QJsonDocument jsonDoc{object};
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc.toJson(QJsonDocument::Compact);
    ClientSocket->write(block);
  }

void TcpServer::ReadMessage()
{
    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    in.setDevice(clientSocket);
    while(!in.atEnd())
    {
        in.startTransaction();

        QByteArray jsonData;

        in >> jsonData;

        if(!in.commitTransaction())
        {
            qDebug() << "This happened!";
            return;
        }
        QJsonDocument JsonDoc = QJsonDocument::fromJson(jsonData);
        QJsonObject JsonObj = JsonDoc.object();

        if (JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameEnd))
        {
            qDebug() << "Game End!";
        }
        else if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameUpdate))
        {
            QString userAnswer = JsonObj["Answer"].toString();
            int ClientId = ClientIds[clientSocket];
            qDebug() << "Answer recieved from client " << userAnswer;
            emit ClientAnswerRecieved(userAnswer, ClientId);
        }
        else if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameUpdateUserStatus))
        {
            int ClientId = ClientIds[clientSocket];
            ClientStates[ClientId] = !ClientStates[ClientId];
            QString Username = ClientUsernames[ClientId];
            QString Table = JsonObj["Data"].toString();
            qDebug() << "User : " << Username << " now has state : " << ClientStates[ClientId];
            // Msg the new State to all clients so it appears correctly on their screen
            QJsonObject Data
            {
                {"Username", Username},
                {"Table",  Table},
            };
            MessageOtherClientsData(ServerMessageTypes::GameUpdateUserStatus, Data, ClientId);
//            MessageOtherClients(ServerMessageTypes::GameUpdateUserStatus, Username, ClientId);
            qDebug() << "Table that changed " << Table;
            if(Table == "Scoreboard")
                emit ClientScoreboardStateChanged(Username);
            else
                emit ClientStateChanged(Username);
        }
        else if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameSendUsername))
        {
            QString Username = JsonObj["Data"].toString().simplified();
            int ClientId = ClientIds[clientSocket];
            // 1) Check that username doesn't already exist
            if(Username == ServerUsername)
            {
                MessageClient(ServerMessageTypes::GameUsernameTaken, ClientId, "");
                return;
            }
            for(auto &value : ClientUsernames)
            {
                if(value == Username)
                {
                    MessageClient(ServerMessageTypes::GameUsernameTaken, ClientId, "");
                    return;
                }
            }
            // 2) Send all other usernames to that client
            for(auto it = ClientIndex.begin(); it != ClientIndex.end(); it++)
            {
                auto key = it.key();
                if(key == ClientId)
                   continue;
                QString ClientUsername = ClientUsernames[key];
                bool ClientState = ClientStates[key];
                QJsonObject Data
                {
                    {"Username", ClientUsername},
                    {"State",  ClientState},
                };
                MessageClientData(ServerMessageTypes::GameSendUsername, Data, ClientId);
            }
            // 3) Send the newly connected client the ServerUsername
            MessageClient(ServerMessageTypes::GameSendServerUsername, ClientId, ServerUsername);
            emit ClientUsernameRecieved(Username, ClientId);
            // 4) Send the newly connected client name to all other connected clients.
            QJsonObject Data
            {
                {"Username", Username},
                {"State",  false},
            };
            MessageOtherClientsData(ServerMessageTypes::GameSendUsername, Data, ClientId);
            ClientUsernames.insert(ClientId, Username);
            MessageClient(ServerMessageTypes::GameUsernameAccepted, ClientId, "");
        }
    }
}

void TcpServer::ClientConnected()
{
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    connect(clientSocket, &QIODevice::readyRead, this, &TcpServer::ReadMessage);
    connect(clientSocket, &QTcpSocket::disconnected, this, &TcpServer::HandleDisconnect);
    Connections.push_back(clientSocket);
    ClientIds.insert(clientSocket, UserCount);
    ClientIndex.insert(UserCount, clientSocket);
    ClientStates.insert(UserCount, false);
    UserCount++;
    qDebug() << "New Client has joined! There are now " << ClientIds.size() << " clients";
}

void TcpServer::HandleDisconnect()
{
    // Called when a client disconnects
    // Remove the client from each QHash
    // Remove that individual client from each persons UserTable
    QTcpSocket* ClientSocket = qobject_cast<QTcpSocket*>(sender());
    int ClientId = ClientIds[ClientSocket];
    emit HandleClientDisconnect(ClientId);
    emit RemoveClientFromTable(ClientUsernames[ClientId]);
    qDebug() << "Removing client with Id " << ClientId;
    MessageOtherClients(ServerMessageTypes::GameClientDisconnect, ClientUsernames[ClientId], ClientId);
    ClientIds.remove(ClientSocket);
    ClientIndex.remove(ClientId);
    ClientUsernames.remove(ClientId);
    ClientStates.remove(ClientId);
}

void TcpServer::MessageOtherClientsData(ServerMessageTypes UpdateType, QJsonObject Data, int ClientId)
{
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(UpdateType).toJsonValue()},
        {"Data", Data},
    };
    QJsonDocument jsonDoc{object};
    for(const auto &key : ClientIndex.keys())
    {
        if(key == ClientId)
            continue;
        QTcpSocket* connection = ClientIndex[key];
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << jsonDoc.toJson(QJsonDocument::Compact);
        connection->write(block);
    }
}

void TcpServer::MessageOtherClients(ServerMessageTypes UpdateType, QString Data, int ClientId)
{
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(UpdateType).toJsonValue()},
        {"Data", Data},
    };
    QJsonDocument jsonDoc{object};
    for(auto it = ClientIndex.begin(); it != ClientIndex.end(); it++)
    {
        auto key = it.key();
        if(key == ClientId)
            continue;
        QTcpSocket* connection = ClientIndex[key];
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << jsonDoc.toJson(QJsonDocument::Compact);
        connection->write(block);
    }
}

void TcpServer::MessageAll(ServerMessageTypes updateType, QString question)
{
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(updateType).toJsonValue()},
        {"Data", question},
    };
    QJsonDocument jsonDoc{object};
    for (auto connection : Connections)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_2);
        out << jsonDoc.toJson(QJsonDocument::Compact);
        connection->write(block);
    }
}

bool TcpServer::AllPlayersReady()
{
    for(auto value : ClientStates)
    {
        if(value != true)
            return false;
    }
    std::fill(ClientStates.begin(), ClientStates.end(), false);
    return true;
}

bool TcpServer::StartGame(QString Question)
{
    // Check if all players are ready
    for(auto value : ClientStates)
    {
        if(value != true)
            return false;
    }
    MessageAll(ServerMessageTypes::GameStart, Question);
    return true;
}


void TcpServer::CloseServer()
{
    qDebug() << "Stopping Tcp Server!";
    tcpServer->deleteLater();
}




