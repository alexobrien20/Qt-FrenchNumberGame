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
    QWidget* MainScreenPage = ui->stackedWidget->widget(1);
    QWidget* GameSettingsPage = ui->stackedWidget->widget(0);
    ui->stackedWidget->setCurrentWidget(MainScreenPage);
    ui->LowestInput->setValidator(RangeValidator);
    ui->HighestInput->setValidator(RangeValidator);
    ui->AmountInput->setValidator(AmountValidator);
    ui->stackedWidget->addWidget(GamePage);
    ui->stackedWidget->addWidget(EndPage);
    ui->stackedWidget->addWidget(MultiPlayerPage);
    connect(ui->StartButton, &QPushButton::clicked, this, &MainMenu::StartButtonClicked);
    connect(GamePage, &GameScreen::GameOverSignal, this, &MainMenu::SetEndScreenWidget);
    connect(EndPage, &EndScreen::AgainButtonClicked, this, &MainMenu::StartButtonClicked);
    connect(EndPage, &EndScreen::MenuButtonClicked, this, [=](){this->ui->stackedWidget->setCurrentWidget(MainScreenPage);});
    connect(MultiPlayerPage, &MultiPlayerScreen::MenuButtonClickedSignal, this, [=](){this->ui->stackedWidget->setCurrentWidget(MainScreenPage);});
    connect(ui->SinglePlayerButton, &QPushButton::clicked, this, [=](){this->ui->stackedWidget->setCurrentWidget(GameSettingsPage);});
    connect(ui->MultiPlayerButton, &QPushButton::clicked, this, [=](){this->ui->stackedWidget->setCurrentWidget(MultiPlayerPage);});
    connect(ui->MainMenuButton, &QPushButton::clicked, this, [=](){this->ui->stackedWidget->setCurrentWidget(MainScreenPage);});
}

void MainMenu::StartButtonClicked()
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



