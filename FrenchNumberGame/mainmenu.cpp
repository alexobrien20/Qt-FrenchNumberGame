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
    connect(ui->StartButton, &QPushButton::pressed, this, &MainMenu::on_StartButton_clicked);
    connect(EndPage, )
    ui->stackedWidget->addWidget(GamePage);
    ui->stackedWidget->addWidget(EndPage);
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
    ui->stackedWidget->setCurrentIndex(1);
    GamePage->StartGame(Lowest, Highest, Amount);
}


MainMenu::~MainMenu()
{
    delete ui;
}



