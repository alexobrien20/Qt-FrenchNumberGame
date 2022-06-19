/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *GameSettingsScreen;
    QVBoxLayout *verticalLayout_3;
    QLabel *MenuLabel;
    QLabel *ErrorLabel;
    QGridLayout *gridLayout;
    QLineEdit *HighestInput;
    QLabel *AmountLabel;
    QLabel *LowestLabel;
    QLabel *HighestLabel;
    QPushButton *StartButton;
    QLineEdit *LowestInput;
    QLineEdit *AmountInput;
    QWidget *MainMenuScreen;
    QVBoxLayout *verticalLayout_4;
    QLabel *MenuLabel_2;
    QPushButton *SinglePlayerButton;
    QPushButton *MultiPlayerButton;
    QWidget *MultiPlayerSettingsScreen;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLineEdit *PortInput;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *StartServerButton;
    QPushButton *JoinServerButton;
    QPushButton *MainMenuButton;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(600, 600);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        GameSettingsScreen = new QWidget();
        GameSettingsScreen->setObjectName(QString::fromUtf8("GameSettingsScreen"));
        verticalLayout_3 = new QVBoxLayout(GameSettingsScreen);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        MenuLabel = new QLabel(GameSettingsScreen);
        MenuLabel->setObjectName(QString::fromUtf8("MenuLabel"));
        MenuLabel->setStyleSheet(QString::fromUtf8("font-size: 40px;\n"
"font-weight: bold;"));

        verticalLayout_3->addWidget(MenuLabel, 0, Qt::AlignHCenter);

        ErrorLabel = new QLabel(GameSettingsScreen);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setStyleSheet(QString::fromUtf8("color:red;"));

        verticalLayout_3->addWidget(ErrorLabel, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(50, 50, 50, 50);
        HighestInput = new QLineEdit(GameSettingsScreen);
        HighestInput->setObjectName(QString::fromUtf8("HighestInput"));

        gridLayout->addWidget(HighestInput, 1, 1, 1, 1);

        AmountLabel = new QLabel(GameSettingsScreen);
        AmountLabel->setObjectName(QString::fromUtf8("AmountLabel"));

        gridLayout->addWidget(AmountLabel, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        LowestLabel = new QLabel(GameSettingsScreen);
        LowestLabel->setObjectName(QString::fromUtf8("LowestLabel"));

        gridLayout->addWidget(LowestLabel, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        HighestLabel = new QLabel(GameSettingsScreen);
        HighestLabel->setObjectName(QString::fromUtf8("HighestLabel"));

        gridLayout->addWidget(HighestLabel, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        StartButton = new QPushButton(GameSettingsScreen);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));

        gridLayout->addWidget(StartButton, 2, 0, 1, 3);

        LowestInput = new QLineEdit(GameSettingsScreen);
        LowestInput->setObjectName(QString::fromUtf8("LowestInput"));

        gridLayout->addWidget(LowestInput, 1, 0, 1, 1);

        AmountInput = new QLineEdit(GameSettingsScreen);
        AmountInput->setObjectName(QString::fromUtf8("AmountInput"));

        gridLayout->addWidget(AmountInput, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalLayout_3->setStretch(0, 60);
        verticalLayout_3->setStretch(2, 40);
        stackedWidget->addWidget(GameSettingsScreen);
        MainMenuScreen = new QWidget();
        MainMenuScreen->setObjectName(QString::fromUtf8("MainMenuScreen"));
        verticalLayout_4 = new QVBoxLayout(MainMenuScreen);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        MenuLabel_2 = new QLabel(MainMenuScreen);
        MenuLabel_2->setObjectName(QString::fromUtf8("MenuLabel_2"));
        MenuLabel_2->setStyleSheet(QString::fromUtf8("font-size: 40px;\n"
"font-weight: bold;"));

        verticalLayout_4->addWidget(MenuLabel_2, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        SinglePlayerButton = new QPushButton(MainMenuScreen);
        SinglePlayerButton->setObjectName(QString::fromUtf8("SinglePlayerButton"));

        verticalLayout_4->addWidget(SinglePlayerButton);

        MultiPlayerButton = new QPushButton(MainMenuScreen);
        MultiPlayerButton->setObjectName(QString::fromUtf8("MultiPlayerButton"));

        verticalLayout_4->addWidget(MultiPlayerButton);

        stackedWidget->addWidget(MainMenuScreen);
        MultiPlayerSettingsScreen = new QWidget();
        MultiPlayerSettingsScreen->setObjectName(QString::fromUtf8("MultiPlayerSettingsScreen"));
        verticalLayout_2 = new QVBoxLayout(MultiPlayerSettingsScreen);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(MultiPlayerSettingsScreen);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        PortInput = new QLineEdit(MultiPlayerSettingsScreen);
        PortInput->setObjectName(QString::fromUtf8("PortInput"));

        gridLayout_2->addWidget(PortInput, 1, 1, 1, 1);

        lineEdit = new QLineEdit(MultiPlayerSettingsScreen);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);

        label_2 = new QLabel(MultiPlayerSettingsScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        label_3 = new QLabel(MultiPlayerSettingsScreen);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);


        verticalLayout_2->addLayout(gridLayout_2);

        StartServerButton = new QPushButton(MultiPlayerSettingsScreen);
        StartServerButton->setObjectName(QString::fromUtf8("StartServerButton"));

        verticalLayout_2->addWidget(StartServerButton);

        JoinServerButton = new QPushButton(MultiPlayerSettingsScreen);
        JoinServerButton->setObjectName(QString::fromUtf8("JoinServerButton"));

        verticalLayout_2->addWidget(JoinServerButton);

        MainMenuButton = new QPushButton(MultiPlayerSettingsScreen);
        MainMenuButton->setObjectName(QString::fromUtf8("MainMenuButton"));

        verticalLayout_2->addWidget(MainMenuButton);

        stackedWidget->addWidget(MultiPlayerSettingsScreen);

        verticalLayout->addWidget(stackedWidget);

        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        MenuLabel->setText(QCoreApplication::translate("MainMenu", "French Number Game", nullptr));
        ErrorLabel->setText(QString());
        HighestInput->setText(QCoreApplication::translate("MainMenu", "10", nullptr));
        AmountLabel->setText(QCoreApplication::translate("MainMenu", "Amount", nullptr));
        LowestLabel->setText(QCoreApplication::translate("MainMenu", "Lowest", nullptr));
        HighestLabel->setText(QCoreApplication::translate("MainMenu", "Highest", nullptr));
        StartButton->setText(QCoreApplication::translate("MainMenu", "Start", nullptr));
        LowestInput->setText(QCoreApplication::translate("MainMenu", "1", nullptr));
        AmountInput->setText(QCoreApplication::translate("MainMenu", "10", nullptr));
        MenuLabel_2->setText(QCoreApplication::translate("MainMenu", "French Number Game", nullptr));
        SinglePlayerButton->setText(QCoreApplication::translate("MainMenu", "Single Player", nullptr));
        MultiPlayerButton->setText(QCoreApplication::translate("MainMenu", "Multiplayer", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "Mutliplayer!!", nullptr));
        label_2->setText(QCoreApplication::translate("MainMenu", "Host IP", nullptr));
        label_3->setText(QCoreApplication::translate("MainMenu", "Port", nullptr));
        StartServerButton->setText(QCoreApplication::translate("MainMenu", "Start  Server", nullptr));
        JoinServerButton->setText(QCoreApplication::translate("MainMenu", "Join Server", nullptr));
        MainMenuButton->setText(QCoreApplication::translate("MainMenu", "Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
