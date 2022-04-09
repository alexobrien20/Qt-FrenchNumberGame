#include "multiplauerscreen.h"
#include "ui_multiplauerscreen.h"

MultiPlauerScreen::MultiPlauerScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiPlauerScreen)
{
    ui->setupUi(this);
}

MultiPlauerScreen::~MultiPlauerScreen()
{
    delete ui;
}
