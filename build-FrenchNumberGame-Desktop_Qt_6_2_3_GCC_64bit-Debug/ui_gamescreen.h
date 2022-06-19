/********************************************************************************
** Form generated from reading UI file 'gamescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCREEN_H
#define UI_GAMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScreen
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *WordLabel;
    QGridLayout *gridLayout;
    QPushButton *ClearButton;
    QPushButton *EnterButton;
    QPushButton *SkipButton;
    QLineEdit *UserInput;

    void setupUi(QMainWindow *GameScreen)
    {
        if (GameScreen->objectName().isEmpty())
            GameScreen->setObjectName(QString::fromUtf8("GameScreen"));
        GameScreen->resize(800, 600);
        centralwidget = new QWidget(GameScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WordLabel = new QLabel(centralwidget);
        WordLabel->setObjectName(QString::fromUtf8("WordLabel"));
        WordLabel->setStyleSheet(QString::fromUtf8("font-size: 30px;"));

        verticalLayout->addWidget(WordLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        gridLayout->addWidget(ClearButton, 1, 0, 1, 1);

        EnterButton = new QPushButton(centralwidget);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));

        gridLayout->addWidget(EnterButton, 1, 2, 1, 1);

        SkipButton = new QPushButton(centralwidget);
        SkipButton->setObjectName(QString::fromUtf8("SkipButton"));

        gridLayout->addWidget(SkipButton, 1, 1, 1, 1);

        UserInput = new QLineEdit(centralwidget);
        UserInput->setObjectName(QString::fromUtf8("UserInput"));

        gridLayout->addWidget(UserInput, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

        GameScreen->setCentralWidget(centralwidget);

        retranslateUi(GameScreen);

        QMetaObject::connectSlotsByName(GameScreen);
    } // setupUi

    void retranslateUi(QMainWindow *GameScreen)
    {
        GameScreen->setWindowTitle(QCoreApplication::translate("GameScreen", "MainWindow", nullptr));
        WordLabel->setText(QString());
        ClearButton->setText(QCoreApplication::translate("GameScreen", "Clear", nullptr));
        EnterButton->setText(QCoreApplication::translate("GameScreen", "Enter", nullptr));
        SkipButton->setText(QCoreApplication::translate("GameScreen", "Skip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameScreen: public Ui_GameScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCREEN_H
