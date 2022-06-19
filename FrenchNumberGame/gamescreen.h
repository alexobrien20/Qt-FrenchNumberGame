#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <multiplayerscreen.h>
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
    void SkipButtonClicked();
    void ClearButtonClicked();

public slots:
    void UpdateLabel(QString);

signals:
    void GameOverSignal(int);

private:
    Ui::GameScreen *ui;
    QVector<QString> FrenchNumbersInput;
    QVector<QString> FrenchNumbers;
    QVector<QString> EnglishNumbers;
//    QVector<QString>::iterator CurrentNumber;
    QVector<QString>::Iterator CurrentAnswer;
    QString CurrentNumber;
    void CheckAnswer();
    Game* game = nullptr;
    MultiPlayerScreen MultiPlayerPage;
};

#endif // GAMESCREEN_H
