#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);
}

void EndScreen::SetScore(int Score)
{
    QString ScoreText = QString("You scored %1!").arg(Score);
    ui->ScoreLabel->setText(ScoreText);
}

void EndScreen::on_AgainButton_clicked()
{
    emit AgainButtonClicked();
}

void EndScreen::on_MenuButton_clicked()
{
    emit MenuButtonClicked();
}

EndScreen::~EndScreen()
{
    delete ui;
}



