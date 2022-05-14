#include "tcpclient.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QBuffer>

enum class ServerMessageTypes
{
    GameStart,
    GameEnd,
    GameUpdate,
    GameScoreUpdate,
};

TcpClient::TcpClient(QObject *parent)
    : QObject{parent}
{
//    connect(tcpSocket, &QAbstractSocket::connected, this, &MultiPlayerScreen::ClientConnected);

    // Add validators for this!
    tcpSocket = new QTcpSocket(this);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_6_2);
    qDebug() << "TcpSocket created!";

    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &TcpClient::HandleError);
    connect(tcpSocket, &QAbstractSocket::connected, this, &TcpClient::ClientConnected);
    connect(tcpSocket, &QIODevice::readyRead, this, &TcpClient::MessageRecieved);
    connect(tcpSocket, &QAbstractSocket::disconnected, this, &TcpClient::HandleDisconnect);
    // This is deleted correctly yes?
//    connect(tcpSocket, &QAbstractSocket::disconnected, this, [=](){ui->stackedWidget->setCurrentIndex(0);});
}

void TcpClient::RequestNewAnswer(QString answer)
{
    QJsonObject object
    {
        {"MessageType", QVariant::fromValue(ServerMessageTypes::GameUpdate).toJsonValue()},
        {"Answer", answer}
    };
    QJsonDocument jsonDoc{object};
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << jsonDoc.toJson(QJsonDocument::Compact);
    tcpSocket->write(block);
}

void TcpClient::MessageRecieved()
{

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

        if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameStart))
        {
            QString question = JsonObj["Question"].toString();
            emit GameStarted(question);
        }
        else if (JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameEnd))
        {
            int Score = JsonObj["Question"].toString().toInt();
            qDebug() << "Game End!";
            emit GameEnded(Score, true);
        }
        else if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameUpdate))
        {
            QString question = JsonObj["Question"].toString();
            emit GameUpdated(question);
        }
        else if(JsonObj["MessageType"].toInt() == static_cast<int>(ServerMessageTypes::GameScoreUpdate))
        {
            int Score = JsonObj["Question"].toString().toInt();
            qDebug() << "Another player scored " << Score;
            emit GameScoreUpdate(Score);
        }
    }
}

void TcpClient::ClientConnected()
{
    emit ClientConnectedSignal();
}

void TcpClient::ConnectToServer(const QHostAddress HostIp, int Port)
{
    tcpSocket->connectToHost(HostIp, Port);
}

void TcpClient::HandleDisconnect()
{
    tcpSocket->deleteLater();
    qDebug() << "You were disconnected from the server!";
//    tcpSocket->state();
    emit ClientDisconnected();
}

void TcpClient::HandleError(QAbstractSocket::SocketError SocketError)
{
    // Do more with this
    QString error;
    switch(SocketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        error = tr("The Host connection was closed");
        break;
    case QAbstractSocket::HostNotFoundError:
        error = tr("The host was not found!");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        error = tr("Connection was refused!");
        qDebug() << "Connection was refused";
        break;
    default:
        error = tr("The following error occured %1.").arg(tcpSocket->errorString());
    }
    emit ClientErrorSignal(error);
}

QAbstractSocket::SocketState TcpClient::GetState()
{
    qDebug() << "This ran";
    qDebug() << tcpSocket->state();
    if(tcpSocket == nullptr)
        return QAbstractSocket::UnconnectedState;
    return tcpSocket->state();
}

void TcpClient::CloseClient()
{
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
        tcpSocket->deleteLater();
}
