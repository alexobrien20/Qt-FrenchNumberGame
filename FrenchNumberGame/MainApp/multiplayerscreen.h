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
    void PlayAgainButtonClicked();
    void CheckAllUsersReady(QString);

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
    void CanReturnToLobby(int);

private slots:
    void JoinServerButtonClicked();
    void MenuButtonClicked();
    void ClientConnected();
    void StartGameButtonClicked();
    void DisplayError(QString);
    void SetUpGameScreen(QString);
    void SkipButtonClicked();
    void EnterButtonClicked();
    void UsernameEnterButtonClicked();
    void UpdateServerUserTable(QString);
    void UpdateUserTable(QString, bool, bool);
    void HandleClientDisconnect();
    void ClientUsernameAccepted();
    void HandleGameInProgress();
    void StartServerClicked();

private:
    void UpdateUserStatus(QString, QString);
    void ResetTableStatus(QString);
    void RemoveUserFromTable(QString, QString);
    QHostAddress ServerAddress;
    quint16 ServerPort;
    Ui::MultiPlayerScreen *ui;
    QPointer<TcpClient> tcpClient;
    QPointer<TcpServer> tcpServer;
    Game* game = nullptr;
    bool ServerHostB = false;
    QString Username;
};

#endif // MULTIPLAYERSCREEN_H
