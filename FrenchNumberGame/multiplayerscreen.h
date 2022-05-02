#ifndef MULTIPLAYERSCREEN_H
#define MULTIPLAYERSCREEN_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <tcpserver.h>
#include <tcpclient.h>
#include <game.h>
#include <endscreen.h>

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

signals:
    void MenuButtonClickedSignal();
    void GameStarted(QString);
    void GameEnded(int, bool);
    void ClientSendAnswer(QString);
    void GameScoreUpdated(int);
    void CloseServer();

private slots:
    void StartServerButtonClicked();
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

private:
    Ui::MultiPlayerScreen *ui;
    TcpServer* tcpServer = nullptr;
    TcpClient* tcpClient = nullptr;
    Game* game = nullptr;
    bool ServerHostB = false;
};

#endif // MULTIPLAYERSCREEN_H
