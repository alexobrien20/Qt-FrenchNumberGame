#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>

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
    void on_EnterButton_clicked();
    void on_SkipButton_clicked();
    void on_ClearButton_clicked();

signals:
    void GameOverSignal(int);

private:
    Ui::GameScreen *ui;
    QString NumberToFrench(uint);
    QString NumberToEnglish(uint);
    QVector<QString> FrenchNumbersInput;
    QVector<QString> FrenchNumbers;
    QVector<QString> EnglishNumbers;
    QVector<QString>::iterator CurrentNumber;
    QVector<QString>::Iterator CurrentAnswer;
    void LoadFrenchNumbers();
    void CheckAnswer();
    int Score = 0;
};

#endif // GAMESCREEN_H
