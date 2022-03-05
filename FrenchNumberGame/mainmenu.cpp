#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QIntValidator>
#include <QDebug>

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QValidator* RangeValidator = new QIntValidator(1, INT_MAX, this);
    QValidator* AmountValidator = new QIntValidator(1, 100, this);
    ui->LowestInput->setValidator(RangeValidator);
    ui->HighestInput->setValidator(RangeValidator);
    ui->AmountInput->setValidator(AmountValidator);
    ui->stackedWidget->addWidget(GamePage);
    ui->stackedWidget->addWidget(EndPage);
    connect(ui->StartButton, &QPushButton::pressed, this, &MainMenu::on_StartButton_clicked);
    connect(GamePage, &GameScreen::GameOverSignal, this, &MainMenu::SetEndScreenWidget);
    connect(EndPage, &EndScreen::AgainButtonClicked, this, &MainMenu::on_StartButton_clicked);
    connect(EndPage, &EndScreen::MenuButtonClicked, this, [this](){this->ui->stackedWidget->setCurrentIndex(0);});
}

void MainMenu::on_StartButton_clicked()
{
    long Lowest = ui->LowestInput->text().toUInt();
    long Highest = ui->HighestInput->text().toUInt();
    int Amount = ui->AmountInput->text().toUInt();
    if(Highest < Lowest)
    {
        ui->ErrorLabel->setText(tr("Highest must be greater or equal to lowest!"));
    }
    else if(Lowest == 0)
    {
        ui->ErrorLabel->setText(tr("Lowest must be greater than zero!"));
    }
    ui->stackedWidget->setCurrentWidget(GamePage);
    GamePage->StartGame(Lowest, Highest, Amount);
}

void MainMenu::SetEndScreenWidget(int Score)
{
    EndPage->SetScore(Score);
    ui->stackedWidget->setCurrentWidget(EndPage);
}



MainMenu::~MainMenu()
{
    delete ui;
}



