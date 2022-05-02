#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QFile>
#include <QDebug>
#include <QRandomGenerator64>

GameScreen::GameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
}

void GameScreen::UpdateLabel(QString Data)
{
    qDebug() << "Changing Label!";
    ui->WordLabel->setText(Data);
}

void GameScreen::StartGame(uint Lowest, uint Highest, int Amount)
{
    game = new Game(nullptr, this);
    game->StartGame(Lowest, Highest, Amount);
    ui->WordLabel->setText(game->GetCurrentNumber());
}

void GameScreen::on_EnterButton_clicked()
{
    QString UserAnswer = ui->UserInput->text();
    game->CheckAnswer(UserAnswer);
    CurrentNumber = game->Increment();
    if(CurrentNumber.isEmpty())
    {
        emit GameOverSignal(game->Score);
        return;
    }
    ui->WordLabel->setText(CurrentNumber);
    ui->UserInput->setText("");
}

void GameScreen::on_SkipButton_clicked()
{
    CurrentNumber = game->Increment();
    if(CurrentNumber.isEmpty())
    {
        emit GameOverSignal(game->Score);
        return;
    }
    ui->WordLabel->setText(CurrentNumber);
    ui->UserInput->setText("");
}

void GameScreen::on_ClearButton_clicked()
{
    ui->UserInput->setText("");
}

GameScreen::~GameScreen()
{
    delete ui;
}
