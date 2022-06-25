#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);
    ui->Scoreboard->sortByColumn(1, Qt::SortOrder::DescendingOrder);
    // Make sure this delets the other instance

    connect(ui->MultiMenuButton, &QPushButton::clicked, this, [=](){
        emit MultiMenuButtonClicked();
        emit MenuButtonClicked();
        ui->Scoreboard->setRowCount(0);});

//    connect(ui->MultiLobbyButton, &QPushButton::clicked, this, [=](){
//        // Needs to delete tcpClient if client.
//        int index = IsClient ? 2 : 1;
//        emit MultiLobbyButtonClicked(index);
//        ui->Scoreboard->setRowCount(0);});

    connect(ui->MultiLobbyButton, &QPushButton::clicked, this, &EndScreen::HandleMultiplayerLobby);
    connect(ui->MultiAgainButton, &QPushButton::clicked, this, &EndScreen::HandleMultiplayerAgain);
    connect(ui->AgainButton, &QPushButton::clicked, this, &EndScreen::HandleAgainButtonClicked);
    connect(ui->MenuButton, &QPushButton::clicked, this, &EndScreen::HandleMenuButtonClicked);
}

void EndScreen::SetScore(int Score)
{
    QString ScoreText = QString("You scored %1!").arg(Score);
    ui->ScoreLabel->setText(ScoreText);
}

void EndScreen::UpdateScoreboardState(QString Username)
{
    QList<QTableWidgetItem*> Matches = ui->Scoreboard->findItems(Username, Qt::MatchExactly);
    int UsernameRow = ui->Scoreboard->row(Matches[0]);
    QColor CurrentColour = ui->Scoreboard->item(UsernameRow, 2)->background().color();
    QColor newColour = CurrentColour == QColor("lime") ? QColor(255,255,255) : QColor("lime");
    ui->Scoreboard->item(UsernameRow, 2)->setBackground(newColour);
}

void EndScreen::NotAllPlayersReady()
{
    ui->MultiAgainButton->setText(tr("Not all players are ready!"));
}

void EndScreen::HandleMultiplayerLobby()
{
    if(IsClient)
    {

        emit ClientStateChanged("Scoreboard");
        UpdateScoreboardState(ClientUsername);
        return;
    }
    emit ServerCheckStatuses("Lobby");
}

void EndScreen::HandleMultiplayerAgain()
{
    // If Client then update your state and send it to the server
    if(IsClient)
    {

        emit ClientStateChanged("Scoreboard");
        UpdateScoreboardState(ClientUsername);
        return;
    }
    emit ServerCheckStatuses("Again");
    // Else your the server and you want to try and play again
    // We have to check all the states are ready.
//    emit MultiPlayAgainClicked();
//    ui->Scoreboard->setRowCount(0);
}

void EndScreen::UpdateScoreboard(int Score, QString Username, bool BServer)
{
    qDebug() << "Another score " << Score;
    ui->Scoreboard->setSortingEnabled(false);
    int NextRow = ui->Scoreboard->rowCount();
    ui->Scoreboard->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(Username);
    QTableWidgetItem* ScoreItem = new QTableWidgetItem(QString::number(Score));
    QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
    ui->Scoreboard->setItem(NextRow,0, IdItem);
    ui->Scoreboard->setItem(NextRow,1, ScoreItem);
    ui->Scoreboard->setItem(NextRow, 2, ReadyItem);
    if(BServer)
        ui->Scoreboard->item(NextRow,2)->setBackground(QColor(0,255,0));
    ui->Scoreboard->setSortingEnabled(true);
    qDebug() << "No this is called!";
}

void EndScreen::MultiPlayerSetUp(int Score, bool BClient, QString Username)
{
    ui->Scoreboard->setRowCount(0);
    IsClient = BClient;
    ClientUsername = Username;
    this->ui->stackedWidget->setCurrentIndex(1);
    ui->Scoreboard->setSortingEnabled(false);
    int NextRow = ui->Scoreboard->rowCount();
    ui->Scoreboard->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(Username);
    // Might not need to turn it off.
    QTableWidgetItem* ScoreItem = new QTableWidgetItem(QString::number(Score));
    QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
    ui->Scoreboard->setItem(NextRow,0, IdItem);
    ui->Scoreboard->setItem(NextRow,1, ScoreItem);
    ui->Scoreboard->setItem(NextRow,2, ReadyItem);
    if(!BClient)
        ui->Scoreboard->item(NextRow, 2)->setBackground(QColor(0,255,0));
    ui->Scoreboard->setSortingEnabled(true);
}


void EndScreen::HandleAgainButtonClicked()
{
    emit AgainButtonClicked();
}

void EndScreen::HandleMenuButtonClicked()
{
    emit MenuButtonClicked();
}

EndScreen::~EndScreen()
{
    delete ui;
}



