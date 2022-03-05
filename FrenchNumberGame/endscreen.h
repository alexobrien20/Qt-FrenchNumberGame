#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>

namespace Ui {
class EndScreen;
}

class EndScreen : public QWidget
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    void SetScore(int);
    ~EndScreen();

private slots:
    void on_AgainButton_clicked();
    void on_MenuButton_clicked();

signals:
    void MenuButtonClicked();
    void AgainButtonClicked();


private:
    Ui::EndScreen *ui;
};

#endif // ENDSCREEN_H
