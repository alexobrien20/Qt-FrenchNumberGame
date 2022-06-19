#ifndef MULTIPLAYERSCREEN_H
#define MULTIPLAYERSCREEN_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <tcpserver.h>
#include <tcpclient.h>
#include <game.h>
#include <endscreen.h>
#include <QPointer>

namespace Ui {
class MultiPlayerScreen;
}

class MultiPlayerScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MultiPlayerScreen(QWidget *parent = nullptr);
    ~MultiPlayerScreen();

public slots:
    void DisconnectSocket();
    void ChangeWidgetIndex(int);
    void ReadyButtonClicked();
    void PlayAgainButtonClicked();
    void CheckAllUsersReady();

signals:
    void MenuButtonClickedSignal();
    void GameStarted(QString);
    void GameEnded(int, bool, QString);
    void ClientSendAnswer(QString);
    void GameScoreUpdated(int, QString, bool);
    void CloseServer();
    void CloseClient();
    void GamePlayAgainReset();
    void ClientSendUsername(QString);
    void UserReady(QString);
    void UpdateScoreboardState(QString);
    void CanPlayAgain();
    void NotAllPlayersReady();
    void CheckAndChangeWidget();

private slots:
//    void StartServerButtonClicked();
    void JoinServerButtonClicked();
    void MenuButtonClicked();
    void ClientConnected();
    void StartGameButtonClicked();
    void DisplayError(QString);
    void SetUpGameScreen(QString);
    void GameUpdated(QString);
    void SkipButtonClicked();
    void ClearButtonClicked();
    void EnterButtonClicked();
    void UsernameEnterButtonClicked();
    void UpdateServerUserTable(QString);
    void UpdateUserTable(QString, bool, bool);
    void HandleClientDisconnect();
    void UpdateServerState(QString);
    void UpdateClientState(QString);
    void RemoveUserFromServerTable(QString);
    void RemoveUserFromClientTable(QString);

private:
    int FindUsernameRow(QString);
    void ResetTableStatus(QString);
    Ui::MultiPlayerScreen *ui;
//    TcpServer* tcpServer = nullptr;
//    TcpClient* tcpClient = nullptr;
//    QPointer<TcpClient> ClientPtr;
//    QPointer<TcpServer> ServerPtr;
    QPointer<TcpClient> tcpClient;
    QPointer<TcpServer> tcpServer;
    Game* game = nullptr;
    bool ServerHostB = false;
    QString Username;
};

#endif // MULTIPLAYERSCREEN_H
