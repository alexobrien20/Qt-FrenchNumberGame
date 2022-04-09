#include "multiplayerscreen.h"
#include "ui_multiplayerscreen.h"

MultiPlayerScreen::MultiPlayerScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiPlayerScreen)
{
    ui->setupUi(this);

    QWidget* MainPage = ui->stackedWidget->widget(0);
    QWidget* SeverHostPage = ui->stackedWidget->widget(1);
    connect(ui->StartServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::StartServerButtonClicked);
    connect(ui->JoinServerButton, &QPushButton::clicked, this, &MultiPlayerScreen::JoinServerButtonClicked);
    connect(ui->MainMenuButton, &QPushButton::clicked, this, &MultiPlayerScreen::MenuButtonClicked);
}

void MultiPlayerScreen::StartServerButtonClicked()
{
    // Check this for conversion + input validation
    qDebug() << "Clicked!";
    quint16 port = ui->PortInput->text().toInt();
    TcpServer = new QTcpServer(this);
    if(!TcpServer->listen(QHostAddress::Any,35571))
    {
        qDebug() << "Server Listen Error!";
        qDebug() << TcpServer->errorString();
        return;
    }
    QHostAddress ServerHostAddress = TcpServer->serverAddress();
    QString IpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << tr("Server is running on IP : %1 Port : %2").arg(IpAddress).arg(TcpServer->serverPort());
    ui->stackedWidget->setCurrentIndex(1);
    ServerHostB = true;
    ui->ChatBox->appendPlainText(tr("Server is running on IP : %1 Port : %2").arg(IpAddress).arg(TcpServer->serverPort()));
}

void MultiPlayerScreen::JoinServerButtonClicked()
{
    QString ServerIP = ui->HostInput->text();
    int ServerPort = ui->PortInput->text().toInt();
    // Add validators for this!
    TcpSocket = new QTcpSocket(this);
    connect(TcpSocket, &QAbstractSocket::errorOccurred, this, &MultiPlayerScreen::DisplayError);
    connect(TcpSocket, &QAbstractSocket::connected, this, &MultiPlayerScreen::ClientConnected);
    // This is deleted correctly yes?
    connect(TcpSocket, &QAbstractSocket::disconnected, this, [=](){ui->stackedWidget->setCurrentIndex(0);});
    TcpSocket->connectToHost(ServerIP, ServerPort);
}

void MultiPlayerScreen::ClientConnected()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->ChatBox->appendPlainText(tr("Welcome to the server!"));
}


void MultiPlayerScreen::DisplayError(QAbstractSocket::SocketError SocketError)
{
    // Do more with this
    switch(SocketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        ui->ErrorLabel->setText("The host was not found!");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        ui->ErrorLabel->setText("Connection was refused!");
        break;
    default:
        ui->ErrorLabel->setText(tr("The follwing error occured %1.").arg(TcpSocket->errorString()));
    }
}

void MultiPlayerScreen::MenuButtonClicked()
{
    emit MenuButtonClickedSignal();
}

MultiPlayerScreen::~MultiPlayerScreen()
{
    delete ui;
}
