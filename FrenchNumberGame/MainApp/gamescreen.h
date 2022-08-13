#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <game.h>

namespace Ui {
class GameScreen;
}

class GameScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr);
    void StartGame(uint, uint, int);
    ~GameScreen();

private slots:
    void EnterButtonClicked();

signals:
    void GameOverSignal(int);

private:
    Ui::GameScreen *ui;
    void CheckIfGameOver();
    QString CurrentNumber;
    Game* game;
};

#endif // GAMESCREEN_H
