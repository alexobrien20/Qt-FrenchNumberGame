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
}

void MainMenu::on_StartButton_clicked()
{
    qDebug() << "Clicked!";
    int Lowest = ui->LowestInput->text().toInt();
    int Highest = ui->HighestInput->text().toInt();
    if(Highest < Lowest)
    {
        ui->ErrorLabel->setText(tr("Highest must be greater or equal to lowest!"));
    }
    else if(Lowest == 0)
    {
        ui->ErrorLabel->setText(tr("Lowest must be greater than zero!"));
    }
    else if(Highest >= INT_MAX)
    {
        QString ErrorMsg = QString("Highest must be less than %1").arg(INT_MAX);
        ui->ErrorLabel->setText(ErrorMsg);
    }

}

std::string NumberToEnglish(long long number)
{
    std::vector<std::string> TeensEn{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
    std::vector<std::string> TensEn{"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string EnglishNumber = "";
    if(number >= 1000000000)
    {
        int billions = number / 1000000000;
        std::string s = (number - 100 * billions > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(billions) + "billion " + s + NumberToEnglish(number - 1000000000 * billions);
    }
    else if(number >= 1000000)
    {
        int millions = number / 1000000;
        std::string s = (number - 100 * millions > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(millions) + "million " + s + NumberToEnglish(number - 1000000 * millions);
    }
    else if(number >= 1000)
    {
        int thousands = number / 1000;
        std::string s = (number - 100 * thousands > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(thousands) + "thousand " + s + NumberToEnglish(number - 1000 * thousands);
    }
    else if(number >= 100)
    {
        int hundreds = number / 100;
        std::string s = (number - 100 * hundreds > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(hundreds) + "hundred " + s + NumberToEnglish(number - 100 * hundreds);
    }
    else if(number >= 20)
    {
        int tens = number / 10;
        EnglishNumber += TensEn[tens - 2] + " " + NumberToEnglish(number - 10 * tens);
    }
    else if(number > 0)
    {
        EnglishNumber += TeensEn[number - 1] + " ";
        return EnglishNumber;
    }
    return EnglishNumber;
}

std::string NumberToFrench(long long number, std::vector<std::string> FrenchNumbers)
{
    std::string FrenchNumber = "";
    if(number >= 1000000000)
    {
        int billions = number / 1000000000;
        std::string plural = (billions == 1) ? " " : "s ";
        FrenchNumber += NumberToFrench(billions, FrenchNumbers) + "milliard" + plural + NumberToFrench(number - 1000000000 * billions, FrenchNumbers);
    }
    else if(number >= 1000000)
    {
        int millions = number / 1000000;
        std::string plural = (millions == 1) ? " " : "s ";
        FrenchNumber +=  NumberToFrench(millions, FrenchNumbers) + "million"  + plural + NumberToFrench(number - 1000000 * millions, FrenchNumbers);
    }
    else if(number >= 1000)
    {
        int thousands = number / 1000;
        std::string prefix = (thousands == 1) ? "" : NumberToFrench(thousands, FrenchNumbers);
        FrenchNumber +=  prefix + "millie "  + NumberToFrench(number - 1000 * thousands, FrenchNumbers);
    }
    else if(number >= 100)
    {
        int hundreds = number / 100;
        std::string plural = (hundreds == 1) ? " " : "s ";
        std::string prefix = (hundreds == 1) ? "" : FrenchNumbers[hundreds] + " ";
        FrenchNumber +=  prefix + "cent" + plural + NumberToFrench(number - 100 * hundreds, FrenchNumbers);
    }
    else if(number > 0)
    {
        FrenchNumber += FrenchNumbers[number] + " ";
    }
    return FrenchNumber;
}

MainMenu::~MainMenu()
{
    delete ui;
}



