#include "multiplayerscreen.h"
#include "ui_multiplayerscreen.h"

MultiPlayerScreen::MultiPlayerScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiPlayerScreen)
{
    ui->setupUi(this);

    QWidget* MainPage = ui->stackedWidget->widget(0);
    QWidget* SeverHostPage = ui->stackedWidget->widget(1);
    QWidget* GamePage = ui->stackedWidget->widget(3);
    connect(ui->StartServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::StartServerClicked);
    connect(ui->JoinServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::JoinServerButtonClicked);
    connect(ui->MainMenuButton, &QPushButton::clicked, this, &MultiPlayerScreen::MenuButtonClicked);
    connect(ui->StartGameButton, &QPushButton::clicked, this, &MultiPlayerScreen::StartGameButtonClicked);

    connect(ui->EnterButton, &QPushButton::clicked, this, &MultiPlayerScreen::EnterButtonClicked);
    connect(ui->SkipButton, &QPushButton::clicked, this, &MultiPlayerScreen::SkipButtonClicked);
    connect(ui->ClearButton, &QPushButton::clicked, this, &MultiPlayerScreen::ClearButtonClicked);

    connect(ui->UsernameEnterButton, &QPushButton::clicked, this, &MultiPlayerScreen::UsernameEnterButtonClicked);
    connect(ui->ReadyButton, &QPushButton::clicked, this, [this](){emit UserReady("UserTable");});
    connect(ui->ReadyButton, &QPushButton::clicked, this, [this]{UpdateClientState(Username);});
    connect(ui->UsernameMenuButton, &QPushButton::clicked, this, &MultiPlayerScreen::MenuButtonClicked);
}


void MultiPlayerScreen::PlayAgainButtonClicked()
{
    emit UserReady("Scoreboard");
}

void MultiPlayerScreen::StartServerClicked()
{
    // Maybe add validators for this.
    ServerAddress = QHostAddress(ui->HostInput->text());
    ServerPort = ui->PortInput->text().toUInt();
    ui->stackedWidget->setCurrentIndex(4);
}

void MultiPlayerScreen::UpdateUserTable(QString Username, bool BServer, bool BReady)
{
    int NextRow = ui->ClientUserTable->rowCount();
    ui->ClientUserTable->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(Username);
    QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
    ui->ClientUserTable->setItem(NextRow, 0, IdItem);
    ui->ClientUserTable->setItem(NextRow, 1, ReadyItem);
    if(BServer)
        ui->ClientUserTable->item(NextRow, 1)->setBackground(QColor(0,255,0));
    else
    {
        QColor ReadyColor = BReady ? QColor(0,255,0) : QColor(255,255,255);
        ui->ClientUserTable->item(NextRow, 1)->setBackground(ReadyColor);
    }
}

void MultiPlayerScreen::UpdateServerUserTable(QString Username)
{
    int NextRow = ui->ServerUserTable->rowCount();
    ui->ServerUserTable->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(Username);
    QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
    ui->ServerUserTable->setItem(NextRow, 0, IdItem);
    ui->ServerUserTable->setItem(NextRow, 1, ReadyItem);
}

void MultiPlayerScreen::RemoveUserFromServerTable(QString Username)
{
    QList<QTableWidgetItem*> Matches = ui->ServerUserTable->findItems(Username, Qt::MatchExactly);
    int UsernameRow = ui->ServerUserTable->row(Matches[0]);
    ui->ServerUserTable->removeRow(UsernameRow);
}

void MultiPlayerScreen::RemoveUserFromClientTable(QString Username)
{
    QList<QTableWidgetItem*> Matches = ui->ClientUserTable->findItems(Username, Qt::MatchExactly);
    int UsernameRow = ui->ClientUserTable->row(Matches[0]);
    ui->ClientUserTable->removeRow(UsernameRow);
}

void MultiPlayerScreen::ClientUsernameAccepted()
{
    int NextRow = ui->ClientUserTable->rowCount();
    ui->ClientUserTable->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(Username);
    QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
    ui->ClientUserTable->setItem(NextRow, 0, IdItem);
    ui->ClientUserTable->setItem(NextRow, 1, ReadyItem);
    ui->stackedWidget->setCurrentIndex(2);
    ui->UsernameLabel->setText(tr("Please enter a username"));
}

void MultiPlayerScreen::UsernameEnterButtonClicked()
{
    // Add some checks for this.
    Username = ui->UsernameInputBox->text();
    QString UsernameInput = ui->UsernameInputBox->text();
    if(!tcpClient.isNull())
    {
        emit ClientSendUsername(UsernameInput);
    }
    else
    {
        qDebug() << ServerAddress << " " << ServerPort;
        TcpServer* tcpServerSocket = new TcpServer(ServerAddress, ServerPort, UsernameInput, this);
        tcpServer = tcpServerSocket;
        connect(this, &MultiPlayerScreen::CloseServer, tcpServer, &TcpServer::CloseServer);
        connect(tcpServer, &TcpServer::ClientUsernameRecieved, this, &MultiPlayerScreen::UpdateServerUserTable);
        connect(tcpServer, &TcpServer::ClientStateChanged, this, &MultiPlayerScreen::UpdateServerState);
        connect(tcpServer, &TcpServer::ClientScoreboardStateChanged, this, [this](QString Username){emit UpdateScoreboardState(Username);});
        connect(tcpServer, &TcpServer::RemoveClientFromTable, this, &MultiPlayerScreen::RemoveUserFromServerTable);
        connect(tcpServer, &TcpServer::SendUsernameAndScore, this, [this](QString Username, int Score, bool State){emit GameScoreUpdated(Score, Username, State);});
        ServerHostB = true;
        int NextRow = ui->ServerUserTable->rowCount();
        ui->ServerUserTable->insertRow(NextRow);
        QTableWidgetItem* IdItem = new QTableWidgetItem(UsernameInput);
        QTableWidgetItem* ReadyItem = new QTableWidgetItem(tr(""));
        ui->ServerUserTable->setItem(NextRow, 0, IdItem);
        ui->ServerUserTable->setItem(NextRow, 1, ReadyItem);
        ui->ServerUserTable->item(NextRow, 1)->setBackground(QColor(0,255,0));
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MultiPlayerScreen::UpdateServerState(QString Username)
{
    QList<QTableWidgetItem*> Matches = ui->ServerUserTable->findItems(Username, Qt::MatchExactly);
    qDebug() << Matches.size();
    int UsernameRow = ui->ServerUserTable->row(Matches[0]);
    QColor CurrentColour = ui->ServerUserTable->item(UsernameRow, 1)->background().color();
    QColor newColour = CurrentColour == QColor("lime") ? QColor(255,255,255) : QColor("lime");
    ui->ServerUserTable->item(UsernameRow, 1)->setBackground(newColour);
}

void MultiPlayerScreen::UpdateClientState(QString Username)
{
    qDebug() << "Searching for username " << Username;
    QList<QTableWidgetItem*> Matches = ui->ClientUserTable->findItems(Username, Qt::MatchExactly);
    int UsernameRow = ui->ClientUserTable->row(Matches[0]);
    QColor CurrentColour = ui->ClientUserTable->item(UsernameRow, 1)->background().color();
    QColor newColour = CurrentColour == QColor("lime") ? QColor(255,255,255) : QColor("lime");
    ui->ClientUserTable->item(UsernameRow, 1)->setBackground(newColour);
}

void MultiPlayerScreen::ResetTableStatus(QString TableName)
{
    QTableWidget* Table = ui->ClientUserTable;
    if(TableName == "Server")
        Table = ui->ServerUserTable;
    for(int row = 0; row < Table->rowCount(); row++)
    {
        if(Table->item(row, 0)->text() == "Server")
            continue;
        Table->item(row, 1)->setBackground(QColor(255,255,255));
    }
}

void MultiPlayerScreen::ChangeWidgetIndex(int Index)
{
    // Changes the widget depending on if the socket is open
    // End screen -> lobby only if the server is still open.
    if(!tcpClient.isNull())
    {
        ResetTableStatus("User");
        ui->stackedWidget->setCurrentIndex(Index);
    }
    else if(!tcpServer.isNull())
    {
        // If going to lobby then we need to delete the old game.
        if(Index == 1)
        {
            ResetTableStatus("Server");
            game->deleteLater();
        }
        // If we are playing again then a signal needs to be outputted to remove the old scores.
        else if(Index == 4)
        {
            emit GamePlayAgainReset();
        }
        ui->stackedWidget->setCurrentIndex(Index);
    }
    // If no socket then there must be no game open.
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MultiPlayerScreen::DisconnectSocket()
{
    // Called when you exit the game but don't actually close the application.
    if(!tcpServer.isNull())
    {
        tcpServer->deleteLater();
        game->deleteLater();
        ui->ServerUserTable->setRowCount(0);
    }
    else if(!tcpClient.isNull())
    {
        qDebug() << "This is called!";
        tcpClient->deleteLater();
        ui->ClientUserTable->setRowCount(0);
    }
}

void MultiPlayerScreen::JoinServerButtonClicked()
{
    QHostAddress ServerIP = QHostAddress(ui->HostInput->text());
    quint16 ServerPort = ui->PortInput->text().toInt();
    // Add validators for this!
    tcpClient = new TcpClient;
    connect(tcpClient, &TcpClient::ClientErrorSignal, this, &MultiPlayerScreen::DisplayError);
    connect(tcpClient, &TcpClient::ConnectionAccepted, this, &MultiPlayerScreen::ClientConnected);
    connect(tcpClient, &TcpClient::GameStarted, this, &MultiPlayerScreen::SetUpGameScreen);
    connect(tcpClient, &TcpClient::GameUpdated, this, [this](QString Question){ui->WordLabel->setText(Question);});
    connect(tcpClient, &TcpClient::GameEnded, this, [this](int Score, bool BClient){emit GameEnded(Score, BClient, Username);});
    connect(tcpClient, &TcpClient::GameScoreUpdate, [this](int Score, QString Username, bool State){emit GameScoreUpdated(Score, Username, State);});
    connect(tcpClient, &TcpClient::ClientDisconnected, this, &MultiPlayerScreen::HandleClientDisconnect);
    connect(tcpClient, &TcpClient::NewUserJoined, this, &MultiPlayerScreen::UpdateUserTable);
    connect(tcpClient, &TcpClient::UserStateChanged, this, &MultiPlayerScreen::UpdateClientState);
    connect(tcpClient, &TcpClient::OtherClientDisconnected, this, &MultiPlayerScreen::RemoveUserFromClientTable);
    connect(tcpClient, &TcpClient::ClientScoreboardStateChanged, this, [this](QString Username){emit UpdateScoreboardState(Username);});
    connect(tcpClient, &TcpClient::ClientReturnToLobby, this, [this](){emit CanReturnToLobby(2);});
    connect(tcpClient, &TcpClient::UsernameAlreadyTaken, this, [this](){ui->UsernameLabel->setText(tr("Username Already Taken, Please Enter Another!"));});
    connect(tcpClient, &TcpClient::UsernameAccepted, this, &MultiPlayerScreen::ClientUsernameAccepted);
    connect(tcpClient, &TcpClient::GameInProgress, this, &MultiPlayerScreen::HandleGameInProgress);
    connect(this, &MultiPlayerScreen::ClientSendAnswer, tcpClient, &TcpClient::RequestNewAnswer);
    connect(this, &MultiPlayerScreen::CloseClient, tcpClient, &TcpClient::CloseClient);
    connect(this, &MultiPlayerScreen::ClientSendUsername, tcpClient, &TcpClient::SendUsername);
    connect(this, &MultiPlayerScreen::UserReady, tcpClient, &TcpClient::SendUserStatus);
    tcpClient->ConnectToServer(ServerIP, ServerPort);
}

void MultiPlayerScreen::HandleGameInProgress()
{
    // Display an error message here.
    ui->TitleLabel->setText(tr("That game is already in progress!"));
    tcpClient->deleteLater();
    ui->stackedWidget->setCurrentIndex(0);
}

void MultiPlayerScreen::HandleClientDisconnect()
{
    ui->stackedWidget->setCurrentIndex(0);
    tcpClient->deleteLater();
    ui->ClientUserTable->setRowCount(0);
}

void MultiPlayerScreen::SetUpGameScreen(QString question)
{
    qDebug() << "Game set up!";
    emit CheckAndChangeWidget();
    ui->stackedWidget->setCurrentIndex(3);
    ui->WordLabel->setText(question);
}

void MultiPlayerScreen::EnterButtonClicked()
{
    // If server then just update normally
    QString UserAnswer = ui->UserInput->text();
    if(tcpServer)
    {
        QString CurrentNumber = game->CheckServerAnswer(UserAnswer);
        if(CurrentNumber.isEmpty())
        {
            ui->UserInput->setText("");
            return;
        }
        ui->WordLabel->setText(CurrentNumber);
    }
    // If client then send message and ask for new word.
    else if(tcpClient)
    {
        emit ClientSendAnswer(UserAnswer);
    }
    ui->UserInput->setText("");
}

void MultiPlayerScreen::SkipButtonClicked()
{
    if(tcpServer)
    {
        QString CurrentNumber = game->CheckServerAnswer("");
        if(CurrentNumber.isEmpty())
        {
            return;
        }
        ui->WordLabel->setText(CurrentNumber);
    }
    else if(tcpClient)
    {
        emit ClientSendAnswer("");
    }
    ui->UserInput->setText("");
}

void MultiPlayerScreen::ClearButtonClicked()
{
    ui->UserInput->setText("");
}


void MultiPlayerScreen::ClientConnected()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->ChatBox->appendPlainText(tr("Welcome to the server!"));
}


void MultiPlayerScreen::StartGameButtonClicked()
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
    // Check about deleting this variablwe
    if(!tcpServer->AllPlayersReady())
    {
        ui->StartGameButton->setText("Not all players are ready!");
        return;
    }
    game = new Game(tcpServer, Lowest, Highest, Amount, this);
    game->StartMultiplayerGame();
    ui->stackedWidget->setCurrentIndex(3);
    ui->WordLabel->setText(game->GetCurrentNumber());
    connect(game, &Game::GameEnded, this, [this](int Score, bool BClient){emit GameEnded(Score, BClient, Username);});
//    connect(game, &Game::GameScoreUpdate, this, [this](int Score){emit GameScoreUpdated(Score);});
    connect(this, &MultiPlayerScreen::GamePlayAgainReset, game, &Game::ResetGame);
    ui->StartGameButton->setText("Start Game");
}

void MultiPlayerScreen::CheckAllUsersReady(QString Button)
{

    if(!tcpServer->AllPlayersReady())
    {
        emit NotAllPlayersReady();
        return;
    }
    if(Button == "Again")
    {
        emit CanPlayAgain();
        game->StartMultiplayerGame();
        ui->WordLabel->setText(game->GetCurrentNumber());
    }
    // Else we are bring all the players back to the lobby
    else
    {
        emit CanReturnToLobby(1);
        // Turn this into a slot
        tcpServer->MessageAll(ServerMessageTypes::GameReturnToLobby, "");
    }
}

void MultiPlayerScreen::DisplayError(QString SocketError)
{
    ui->ErrorLabel->setText(SocketError);
    if(!tcpClient.isNull())
        tcpClient->deleteLater();
    else if(!tcpServer.isNull())
        tcpServer->deleteLater();
}

void MultiPlayerScreen::MenuButtonClicked()
{
    if(!tcpClient.isNull())
        tcpClient->deleteLater();
    else if(!tcpServer.isNull())
        tcpServer->deleteLater();
    emit MenuButtonClickedSignal();
}

MultiPlayerScreen::~MultiPlayerScreen()
{
    delete ui;
}
