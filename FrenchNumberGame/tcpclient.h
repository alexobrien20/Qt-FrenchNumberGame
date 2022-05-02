#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    TcpClient(QObject *parent = nullptr);
    void ConnectToServer(const QHostAddress HostIP, int Port);
    QAbstractSocket::SocketState GetState();

signals:
    void ClientErrorSignal(QString);
    void ClientConnectedSignal();
    void GameStarted(QString);
    void GameUpdated(QString);
    void GameEnded(int, bool);
    void GameScoreUpdate(int);
    void ClientDisconnected();

public slots:
    void RequestNewAnswer(QString);

private slots:
    void ClientConnected();
    void MessageRecieved();
    void HandleDisconnect();


private:
    QTcpSocket* tcpSocket = nullptr;
    const QHostAddress HostIp;
    int Port;
    void HandleError(QAbstractSocket::SocketError);
    QDataStream in;

};

#endif // TCPCLIENT_H
