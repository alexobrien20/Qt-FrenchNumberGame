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
        ui->Scoreboard->setRowCount(0);;});

    connect(ui->MultiLobbyButton, &QPushButton::clicked, this, [=](){
        // Needs to delete tcpClient if client.
        int index = IsClient ? 2 : 1;
        emit MultiLobbyButtonClicked(index);
        ui->Scoreboard->setRowCount(0);;});

    connect(ui->MultiAgainButton, &QPushButton::clicked, this, [=](){
        emit MultiPlayAgainClicked();
        ui->Scoreboard->setRowCount(0);;});
}

void EndScreen::SetScore(int Score)
{
    QString ScoreText = QString("You scored %1!").arg(Score);
    ui->ScoreLabel->setText(ScoreText);
}

void EndScreen::UpdateScoreboard(int Score)
{
    qDebug() << "Another score " << Score;
    ui->Scoreboard->setSortingEnabled(false);
    int NextRow = ui->Scoreboard->rowCount();
    ui->Scoreboard->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(tr("Not Me"));
    // Might not need to turn it off.
    QTableWidgetItem* ScoreItem = new QTableWidgetItem(QString::number(Score));
    ui->Scoreboard->setItem(NextRow,0, IdItem);
    ui->Scoreboard->setItem(NextRow,1, ScoreItem);
    ui->Scoreboard->setSortingEnabled(true);
}

void EndScreen::MultiPlayerSetUp(int Score, bool BClient)
{
    IsClient = BClient;
    this->ui->stackedWidget->setCurrentIndex(1);
    ui->Scoreboard->setSortingEnabled(false);
    int NextRow = ui->Scoreboard->rowCount();
    ui->Scoreboard->insertRow(NextRow);
    QTableWidgetItem* IdItem = new QTableWidgetItem(tr("Me"));
    // Might not need to turn it off.
    QTableWidgetItem* ScoreItem = new QTableWidgetItem(QString::number(Score));
    ui->Scoreboard->setItem(NextRow,0, IdItem);
    ui->Scoreboard->setItem(NextRow,1, ScoreItem);
    ui->Scoreboard->setSortingEnabled(true);
}


void EndScreen::on_AgainButton_clicked()
{
    emit AgainButtonClicked();
}

void EndScreen::on_MenuButton_clicked()
{
    emit MenuButtonClicked();
}

EndScreen::~EndScreen()
{
    delete ui;
}



