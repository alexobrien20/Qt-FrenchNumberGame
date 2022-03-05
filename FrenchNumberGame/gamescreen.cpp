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
    LoadFrenchNumbers();
}

void GameScreen::LoadFrenchNumbers()
{
    QFile file(":/FrenchNumbers");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could not open file!";
        return;
    }
    while(!file.atEnd())
    {
        QString Input = file.readLine();
        Input = Input.trimmed();
        FrenchNumbersInput.append(Input);
    }
}

void GameScreen::StartGame(uint Lowest, uint Highest, int Amount)
{
    FrenchNumbers.clear();
    EnglishNumbers.clear();
    for(int i = 0; i < Amount; i++)
    {
        quint32 RandomNumber= QRandomGenerator64::global()->bounded(Lowest, Highest);
        QString FrenchWord = NumberToFrench(RandomNumber);
        QString EnglishWord = NumberToEnglish(RandomNumber);
        FrenchNumbers.push_back(FrenchWord);
        EnglishNumbers.push_back(EnglishWord);
    }
    CurrentNumber = EnglishNumbers.begin();
    CurrentAnswer = FrenchNumbers.begin();
    ui->WordLabel->setText(*CurrentNumber);
}

void GameScreen::on_EnterButton_clicked()
{
    QString UserAnswer = ui->UserInput->text();
    if (UserAnswer == *CurrentAnswer)
    {
        Score++;
        qDebug() << "Correct!";
    }
    if(CurrentNumber + 1 == EnglishNumbers.end())
    {
        qDebug() << "Over!";
        emit GameOverSignal(Score);
        return;
    }
    CurrentNumber++;
    CurrentAnswer++;
    ui->WordLabel->setText(*CurrentNumber);
    ui->UserInput->setText("");
}

void GameScreen::on_SkipButton_clicked()
{
    if(CurrentNumber + 1 == EnglishNumbers.end())
    {
        qDebug() << "Over!";
        emit GameOverSignal(Score);
        return;
    }
    CurrentNumber++;
    CurrentAnswer++;
    ui->WordLabel->setText(*CurrentNumber);
    ui->UserInput->setText("");
}

void GameScreen::on_ClearButton_clicked()
{
    ui->UserInput->setText("");
}


QString GameScreen::NumberToEnglish(uint number)
{
    QVector<QString> TeensEn{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen"};
    QVector<QString> TensEn{"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    QString EnglishNumber = "";
    if(number >= 1000000000)
    {
        int billions = number / 1000000000;
        QString s = (number - 100 * billions > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(billions) + "billion " + s + NumberToEnglish(number - 1000000000 * billions);
    }
    else if(number >= 1000000)
    {
        int millions = number / 1000000;
        QString s = (number - 100 * millions > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(millions) + "million " + s + NumberToEnglish(number - 1000000 * millions);
    }
    else if(number >= 1000)
    {
        int thousands = number / 1000;
        QString s = (number - 100 * thousands > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(thousands) + "thousand " + s + NumberToEnglish(number - 1000 * thousands);
    }
    else if(number >= 100)
    {
        int hundreds = number / 100;
        QString s = (number - 100 * hundreds > 0) ? "and " : "";
        EnglishNumber += NumberToEnglish(hundreds) + "hundred " + s + NumberToEnglish(number - 100 * hundreds);
    }
    else if(number >= 20)
    {
        int tens = number / 10;
        EnglishNumber += TensEn[tens - 2] + " " + NumberToEnglish(number - 10 * tens);
    }
    else if(number > 0)
    {
        EnglishNumber += TeensEn[number - 1];
        return EnglishNumber;
    }
    return EnglishNumber;
}

QString GameScreen::NumberToFrench(uint number)
{
    QString FrenchNumber = "";
    if(number >= 1000000000)
    {
        long billions = number / 1000000000;
        QString plural = (billions == 1) ? " " : "s ";
        FrenchNumber += NumberToFrench(billions) + "milliard" + plural + NumberToFrench(number - 1000000000 * billions);
    }
    else if(number >= 1000000)
    {
        int millions = number / 1000000;
        QString plural = (millions == 1) ? " " : "s ";
        FrenchNumber +=  NumberToFrench(millions) + "million"  + plural + NumberToFrench(number - 1000000 * millions);
    }
    else if(number >= 1000)
    {
        int thousands = number / 1000;
        QString prefix = (thousands == 1) ? "" : NumberToFrench(thousands);
        FrenchNumber +=  prefix + "millie "  + NumberToFrench(number - 1000 * thousands);
    }
    else if(number >= 100)
    {
        int hundreds = number / 100;
        QString plural = (number - 100 * hundreds > 0) ? " " : "s ";
        plural = (hundreds == 1) ? " " : plural;
        QString prefix = (hundreds == 1) ? "" : FrenchNumbersInput[hundreds] + " ";
        FrenchNumber +=  prefix + "cent" + plural + NumberToFrench(number - 100 * hundreds);
    }
    else if(number > 0)
    {
        FrenchNumber += FrenchNumbersInput[number];
    }
    return FrenchNumber;
}

GameScreen::~GameScreen()
{
    delete ui;
}




