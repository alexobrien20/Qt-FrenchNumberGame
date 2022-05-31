#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>
#include <tcpclient.h>

namespace Ui {
class EndScreen;
}

class EndScreen : public QWidget
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    void MultiPlayerSetUp(int, bool, QString);
    void SetScore(int);
    ~EndScreen();

public slots:
    void UpdateScoreboard(int, QString);

private slots:
    void on_AgainButton_clicked();
    void on_MenuButton_clicked();

signals:
    void MenuButtonClicked();
    void MultiMenuButtonClicked();
    void AgainButtonClicked();
    void MultiLobbyButtonClicked(int);
    void MultiPlayAgainClicked();


private:
    Ui::EndScreen *ui;
    TcpClient* tcpClient = nullptr;
    bool IsClient;
};

#endif // ENDSCREEN_H
