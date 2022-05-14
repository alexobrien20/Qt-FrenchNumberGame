#include "game.h"
#include <QRandomGenerator64>
#include <QFile>
#include <QDebug>
#include <algorithm>

Game::Game(TcpServer* TCPSERVER, QObject *parent)
    : QObject{parent}, tcpServer{TCPSERVER}, GameFinished{false}
{
    LoadFrenchNumbers();
    if(tcpServer)
    {
        connect(tcpServer, &TcpServer::ClientAnswerRecieved, this, &Game::CheckClientAnswer);
        connect(tcpServer, &TcpServer::HandleClientDisconnect, this, &Game::HandleClientDisconnect);
        connect(this, &Game::ClientGameUpdate, tcpServer, &TcpServer::MessageClient);
    }
}

Game::Game(QString Question, QString Answer)
    : SingleAnswer{Answer}, SingleQuestion{Question}
{
    // Replace this with a TcpServer version of the constructor.
}

void Game::ResetGame()
{
    // Resets the client scores/counts to 0
    for(auto const& key : ClientScores.keys())
    {
        ClientScores[key]["Counter"] = 0;
        ClientScores[key]["Score"] = 0;
    }
    GenerateNumbers();
    Score = 0;
    GameFinished = false;
}

void Game::HandleClientDisconnect(int ClientId)
{
    // If a client has left then remove them from the scores hashMap
    ClientScores.remove(ClientId);
}

QString Game::CheckServerAnswer(QString answer)
{
    if(answer == *CurrentAnswer)
        Score++;

    if(CurrentNumber + 1 == EnglishNumbers.end())
    {
        emit GameEnded(Score, false);
        QString ServerScore = QString::number(Score);
        for(auto const& key : ClientScores.keys())
        {
            if(ClientScores[key]["Counter"] == AmountOfNumbers - 1)
            {
                emit ClientGameUpdate(ServerMessageTypes::GameScoreUpdate, key, ServerScore);
                emit GameScoreUpdate(ClientScores[key]["Score"]);
            }
        }
        GameFinished = true;
        return "";
    }
    CurrentNumber++;
    CurrentAnswer++;
    return *CurrentNumber;
}

void Game::CheckClientAnswer(QString answer, int ClientId)
{
    //If the Client doesn't already exist then add him to the hash
    if(ClientScores.find(ClientId) == ClientScores.end())
    {
        QHash<QString, int> DefaultValues;
        DefaultValues["Score"] = 0;
        DefaultValues["Counter"] = 0;
        ClientScores.insert(ClientId, DefaultValues);
    }
    //Otherwise update the score and counter

    // 1) Check the answer
    // 2) Increment score
    int CurrentPosition = ClientScores[ClientId]["Counter"];
    if(!answer.isEmpty() && answer == FrenchNumbers[CurrentPosition])
    {
        qDebug() << ClientScores[ClientId]["Score"];
        ClientScores[ClientId]["Score"]++;
        qDebug() << ClientScores[ClientId]["Score"];
    }

    // 3) Check if there is another element

    if(CurrentPosition == AmountOfNumbers - 1)
    {
        // Emit some sort of game over signal
        // Then exit game loop
        QString ClientScore = QString::number(ClientScores[ClientId]["Score"]);
        emit ClientGameUpdate(ServerMessageTypes::GameEnd, ClientId, ClientScore);

        // Send all of the other scores where the client has finished their game.
        // && send your score to the people who have finished.
        for(auto const& key : ClientScores.keys())
        {
            if(key != ClientId && ClientScores[key]["Counter"] == AmountOfNumbers - 1)
            {
                qDebug() << "This happened!";
                QString OtherClientScore = QString::number(ClientScores[key]["Score"]);
                emit ClientGameUpdate(ServerMessageTypes::GameScoreUpdate, ClientId, OtherClientScore);
                emit ClientGameUpdate(ServerMessageTypes::GameScoreUpdate, key, ClientScore);
            }

            // If the game is finished then send the client score as well
        }

        if(GameFinished)
        {
            QString ServerScore = QString::number(Score);
            emit ClientGameUpdate(ServerMessageTypes::GameScoreUpdate, ClientId, ServerScore);
            emit GameScoreUpdate(ClientScores[ClientId]["Score"]);
        }

        return;
    }

    // 4) Update ClientScores counter

    ClientScores[ClientId]["Counter"]++;

    // 5) Message client with new word!

    QString NewQuestion = EnglishNumbers[ClientScores[ClientId]["Counter"]];
    emit ClientGameUpdate(ServerMessageTypes::GameUpdate, ClientId, NewQuestion);
}

void Game::ClientUpdate(QString Data)
{
    emit ClientUpdated(Data);
}

void Game::LoadFrenchNumbers()
{
    QFile file(":/FrenchNumbers");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error when opening file!";
        return;
    }
    while(!file.atEnd())
    {
        QString Input = file.readLine();
        Input = Input.trimmed();
        FrenchNumbersInput.append(Input);
    }
}

void Game::GenerateNumbers()
{
    FrenchNumbers.clear();
    EnglishNumbers.clear();
    for(int i = 0; i < AmountOfNumbers; i++)
    {
        quint32 RandomNumber= QRandomGenerator64::global()->bounded(LowestNumber, HighestNumber);
        QString FrenchWord = NumberToFrench(RandomNumber);
        QString EnglishWord = NumberToEnglish(RandomNumber);
        FrenchNumbers.push_back(FrenchWord);
        EnglishNumbers.push_back(EnglishWord);
    }
    CurrentNumber = EnglishNumbers.begin();
    CurrentAnswer = FrenchNumbers.begin();
}

void Game::StartGame(uint Lowest, uint Highest, int Amount)
{
    AmountOfNumbers = Amount;
    HighestNumber = Highest;
    LowestNumber= Lowest;
    GenerateNumbers();
    // If the a server then send to people that it's started.
    if(tcpServer)
    {
        tcpServer->MessageAll(ServerMessageTypes::GameStart, *CurrentNumber);
    }
}

void Game::SetQuestionAndAnswer(QString answer, QString question)
{
    SingleAnswer = answer;
    SingleQuestion =question;
}

QString Game::GetCurrentNumber()
{
    return *CurrentNumber;
}

void Game::ClientCheckAnswer(QString UserAnswer)
{
    if(UserAnswer == SingleAnswer)
        Score++;
    qDebug() << "Client score" << Score;
}
void Game::CheckAnswer(QString UserAnswer)
{
    if(UserAnswer == *CurrentAnswer)
        Score++;
}

QString Game::Increment()
{
    if(CurrentNumber + 1 == EnglishNumbers.end())
    {
        qDebug() << "Over!";
        return "";
    }
    CurrentNumber++;
    CurrentAnswer++;
    return *CurrentNumber;
}

QString Game::NumberToEnglish(uint number)
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

QString Game::NumberToFrench(uint number)
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
