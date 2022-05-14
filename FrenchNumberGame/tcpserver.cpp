#include "tcpserver.h"
#include <QJsonDocument>
#include <QJsonObject>

TcpServer::TcpServer(const QHostAddress Hostname, int PortNumber, QObject *parent)
    : QObject{parent}, HostIp{Hostname}, Port{PortNumber}, UserCount{0}
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

void TcpServer::MessageClient(ServerMessageTypes MessageType, int ClientId, QString newQuestion = "")
{
    QTcpSocket* ClientSocket = ClientIndex[ClientId];
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(MessageType).toJsonValue()},
        {"Question", newQuestion},
    };
    QJsonDocument jsonDoc{object};
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc.toJson(QJsonDocument::Compact);
    ClientSocket->write(block);
}

void TcpServer::SendNewQuestion(QString newQuestion, int ClientId)
{
    QTcpSocket* ClientSocket = ClientIndex[ClientId];
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(ServerMessageTypes::GameUpdate).toJsonValue()},
        {"Question", newQuestion},
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
            emit ClientAnswerRecieved(userAnswer, ClientId);
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
    UserCount++;
    qDebug() << "New Client has joined! There are now " << ClientIds.size() << " clients";
}

void TcpServer::HandleDisconnect()
{
    QTcpSocket* ClientSocket = qobject_cast<QTcpSocket*>(sender());
    int ClientId = ClientIds[ClientSocket];
    emit HandleClientDisconnect(ClientId);
    qDebug() << "Removing client with Id " << ClientId;
    ClientIds.remove(ClientSocket);
    ClientIndex.remove(ClientId);
}

void TcpServer::MessageAll(ServerMessageTypes updateType, QString question)
{
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(updateType).toJsonValue()},
        {"Question", question},
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

void TcpServer::CloseServer()
{
    qDebug() << "Stopping Tcp Server!";
    tcpServer->deleteLater();
}



