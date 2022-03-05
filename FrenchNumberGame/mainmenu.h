#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <gamescreen.h>
#include <endscreen.h>

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
    void on_StartButton_clicked();
    void SetEndScreenWidget(int);

private:
    Ui::MainMenu *ui;
    GameScreen* GamePage = new GameScreen;
    EndScreen* EndPage = new EndScreen;
};
#endif // MAINMENU_H
