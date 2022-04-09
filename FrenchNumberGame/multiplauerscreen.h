#ifndef MULTIPLAUERSCREEN_H
#define MULTIPLAUERSCREEN_H

#include <QWidget>

namespace Ui {
class MultiPlauerScreen;
}

class MultiPlauerScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MultiPlauerScreen(QWidget *parent = nullptr);
    ~MultiPlauerScreen();

private:
    Ui::MultiPlauerScreen *ui;
};

#endif // MULTIPLAUERSCREEN_H
