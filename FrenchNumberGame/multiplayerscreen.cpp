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
    connect(ui->StartServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::StartServerButtonClicked);
    connect(ui->JoinServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::JoinServerButtonClicked);
    connect(ui->MainMenuButton, &QPushButton::clicked, this, &MultiPlayerScreen::MenuButtonClicked);
    connect(ui->StartGameButton, &QPushButton::clicked, this, &MultiPlayerScreen::StartGameButtonClicked);

    connect(ui->EnterButton, &QPushButton::clicked, this, &MultiPlayerScreen::EnterButtonClicked);
    connect(ui->SkipButton, &QPushButton::clicked, this, &MultiPlayerScreen::SkipButtonClicked);
    connect(ui->ClearButton, &QPushButton::clicked, this, &MultiPlayerScreen::ClearButtonClicked);
}

void MultiPlayerScreen::ChangeWidgetIndex(int Index)
{
   // Only change to lobby / Play again if the server is still open!
    if(tcpClient && tcpClient->GetState() == QAbstractSocket::ConnectedState)
    {
        ui->stackedWidget->setCurrentIndex(Index);
    }
    else if(tcpServer)
    {
        ui->stackedWidget->setCurrentIndex(Index);
    }
    // If not connected then send them back to multiplayer main page
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MultiPlayerScreen::DisconnectSocket()
{
    if(tcpServer)
    {
        emit CloseServer();
    }
    else if(tcpClient)
    {

    }
}

void MultiPlayerScreen::StartServerButtonClicked()
{
    // Check this for conversion + input validation
    // What if this errors?
    tcpServer = new TcpServer(QHostAddress::Any, 35571, this);
    connect(this, &MultiPlayerScreen::CloseServer, tcpServer, &TcpServer::CloseServer);
    ui->stackedWidget->setCurrentIndex(1);
    ServerHostB = true;
}

void MultiPlayerScreen::JoinServerButtonClicked()
{
    QString ServerIP = ui->HostInput->text();
    int ServerPort = ui->PortInput->text().toInt();
    // Add validators for this!
    tcpClient = new TcpClient(this);
    connect(tcpClient, &TcpClient::ClientErrorSignal, this, &MultiPlayerScreen::DisplayError);
    connect(tcpClient, &TcpClient::ClientConnectedSignal, this, &MultiPlayerScreen::ClientConnected);
    connect(tcpClient, &TcpClient::GameStarted, this, &MultiPlayerScreen::SetUpGameScreen);
    connect(tcpClient, &TcpClient::GameUpdated, this, &MultiPlayerScreen::GameUpdated);
    connect(tcpClient, &TcpClient::GameEnded, this, [this](int Score, bool BClient){emit GameEnded(Score, BClient);});
    connect(tcpClient, &TcpClient::GameScoreUpdate, [this](int Score){emit GameScoreUpdated(Score);});
    connect(tcpClient, &TcpClient::ClientDisconnected, [this](){this->ui->stackedWidget->setCurrentIndex(0);});
    connect(this, &MultiPlayerScreen::ClientSendAnswer, tcpClient, &TcpClient::RequestNewAnswer);
    tcpClient->ConnectToServer(QHostAddress::Any, 35571);
}

void MultiPlayerScreen::GameUpdated(QString question)
{
    qDebug() << "Changing label to " << question;
    ui->WordLabel->setText(question);
}

void MultiPlayerScreen::SetUpGameScreen(QString question)
{
    qDebug() << "Game set up!";
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
    ui->stackedWidget->setCurrentIndex(2);
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
    game = new Game(tcpServer, this);
    game->StartGame(Lowest, Highest, Amount);
    ui->stackedWidget->setCurrentIndex(3);
    ui->WordLabel->setText(game->GetCurrentNumber());
    connect(game, &Game::GameEnded, this, [this](int Score, bool BClient){emit GameEnded(Score, BClient);});
    connect(game, &Game::GameScoreUpdate, this, [this](int Score){emit GameScoreUpdated(Score);});
}

void MultiPlayerScreen::DisplayError(QString SocketError)
{
    ui->ErrorLabel->setText(SocketError);
}

void MultiPlayerScreen::MenuButtonClicked()
{
    emit MenuButtonClickedSignal();
}

MultiPlayerScreen::~MultiPlayerScreen()
{
    delete ui;
}
