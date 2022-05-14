#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

enum class ServerMessageTypes
{
    GameStart,
    GameEnd,
    GameUpdate,
    GameScoreUpdate,
};

class TcpServer : public QObject
{
    Q_OBJECT

public:
    TcpServer(const QHostAddress HostIP, int Port, QObject *parent = nullptr);
    void MessageAll(ServerMessageTypes, QString);
    QHash<QTcpSocket*, int> ClientIds;
    QHash<int, QTcpSocket*> ClientIndex;

signals:
    void ClientAnswerRecieved(QString, int);
    void ClientSkipRecieved(int);
    void HandleClientDisconnect(int);

public slots:
    void CloseServer();
    void MessageClient(ServerMessageTypes, int, QString);
    void SendNewQuestion(QString, int);

private slots:
    void ClientConnected();
    void ReadMessage();
    void HandleDisconnect();

private:
    QTcpServer* tcpServer = nullptr;
    QVector<QTcpSocket*> Connections;
    const QHostAddress HostIp;
    int Port;
    QDataStream in;
    int UserCount;

};

#endif // TCPSERVER_H
