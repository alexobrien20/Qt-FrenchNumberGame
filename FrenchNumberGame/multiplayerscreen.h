#ifndef MULTIPLAYERSCREEN_H
#define MULTIPLAYERSCREEN_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MultiPlayerScreen;
}

class MultiPlayerScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MultiPlayerScreen(QWidget *parent = nullptr);
    ~MultiPlayerScreen();

signals:
    void MenuButtonClickedSignal();


private slots:
    void StartServerButtonClicked();
    void JoinServerButtonClicked();
    void MenuButtonClicked();
    void ClientConnected();

private:
    Ui::MultiPlayerScreen *ui;
    QTcpServer* TcpServer = nullptr;
    QTcpSocket* TcpSocket = nullptr;
    void DisplayError(QAbstractSocket::SocketError);
    bool ServerHostB = false;
};

#endif // MULTIPLAYERSCREEN_H
