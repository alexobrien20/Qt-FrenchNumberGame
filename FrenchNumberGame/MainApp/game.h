#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <tcpserver.h>
#include <tcpclient.h>
#include <numberconverter.h>

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QObject *parent = nullptr);
    Game(TcpServer* TCPSERVER, uint Lowest, uint Highest, int Amount, QObject *parent = nullptr);
    void StartGame(uint, uint, int);
    void StartMultiplayerGame();
    void CheckAnswer(QString);
    void ClientCheckAnswer(QString);
    QString Increment();
    QString GetCurrentNumber();
    void SetQuestionAndAnswer(QString, QString);
    int Score = 0;
    QString CheckServerAnswer(QString);
    void SkipClientAnswer(int);
    void ResetGame();
    void SetGameUsername(QString);
    QString NumberToFrench(uint);
    QString NumberToEnglish(uint);

private slots:
    void AddClient(QString, int);
    void ClientUpdate(QString);
    void CheckClientAnswer(QString, int);
    void HandleClientDisconnect(int);

signals:
    void ClientUpdated(QString);
    void ClientGameUpdate(ServerMessageTypes, int, QString, int=0);
    void GameEnded(int, bool);
    void GameScoreUpdate(int, int, bool);

private:
    NumberConverter numberConverter;
    TcpServer* tcpServer = nullptr;
    TcpClient* tcpClient = nullptr;
    // ClientId : {"Score : ""}, {"Counter : ""}}
    QHash<int, QHash<QString, int>> ClientScores;
    void GenerateNumbers();
    QVector<QString> FrenchNumbers;
    QVector<QString> EnglishNumbers;
    QVector<QString>::iterator CurrentNumber;
    QVector<QString>::Iterator CurrentAnswer;
    QString SingleAnswer;
    QString SingleQuestion;
    int AmountOfNumbers;
    uint LowestNumber;
    uint HighestNumber;
    bool GameFinished;
};

#endif // GAME_H
