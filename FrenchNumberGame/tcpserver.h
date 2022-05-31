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
    GameSendUsername,
    GameSendServerUsername,
    GameUpdateUserStatus,
};

class TcpServer : public QObject
{
    Q_OBJECT

public:
    TcpServer(const QHostAddress HostIP, int Port, QString Username, QObject *parent = nullptr);
    void MessageAll(ServerMessageTypes, QString);
    QHash<QTcpSocket*, int> ClientIds;
    QHash<int, QTcpSocket*> ClientIndex;
    QHash<int, bool> ClientStates;

signals:
    void ClientAnswerRecieved(QString, int);
    void ClientSkipRecieved(int);
    void HandleClientDisconnect(int);
    void ClientUsernameRecieved(QString, int);
    void SendUsernameAndScore(QString, int);
    void ClientStateChanged(QString);

public slots:
    void CloseServer();
    void MessageClient(ServerMessageTypes, int, QString, int UserId = 0);
    void SendNewQuestion(QString, int);
    void GetClientUsername(int, int);

private slots:
    void ClientConnected();
    void ReadMessage();
    void HandleDisconnect();

private:
    QJsonObject CreateUsernameScoreJsonObject(QString, int, int);
    void MessageOtherClients(ServerMessageTypes, QString, int);
    void MessageOtherClientsData(ServerMessageTypes, QJsonObject, int);
    void MessageClientData(ServerMessageTypes, QJsonObject, int);
    QTcpServer* tcpServer = nullptr;
    QVector<QTcpSocket*> Connections;
    const QHostAddress HostIp;
    int Port;
    QDataStream in;
    int UserCount;
    QHash<int, QString> ClientUsernames;
    QString ServerUsername;
};

#endif // TCPSERVER_H
