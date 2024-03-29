#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <gamescreen.h>
#include <endscreen.h>
#include <multiplayerscreen.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void StartButtonClicked();
    void SetEndScreenWidget(int);
    void SetMultiPlayerEndScreenWidget(int, bool, QString);
    void HandleReturnToLobby(int);
    void CheckAndChangeWidget();

signals:
    void GameStarted();
    void MultiChangeWidgetIndex(int);

private:
    Ui::MainMenu *ui;
    GameScreen* GamePage = new GameScreen;
    EndScreen* EndPage = new EndScreen;
    MultiPlayerScreen* MultiPlayerPage = new MultiPlayerScreen;
};
#endif // MAINMENU_H
