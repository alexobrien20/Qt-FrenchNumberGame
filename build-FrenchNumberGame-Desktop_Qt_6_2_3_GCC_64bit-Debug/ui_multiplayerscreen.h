/********************************************************************************
** Form generated from reading UI file 'multiplayerscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYERSCREEN_H
#define UI_MULTIPLAYERSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiPlayerScreen
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *JoinStartPage;
    QVBoxLayout *verticalLayout_2;
    QLabel *TitleLabel;
    QLabel *ErrorLabel;
    QGridLayout *gridLayout;
    QLineEdit *HostInput;
    QLineEdit *PortInput;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *StartServerButton;
    QPushButton *JoinServerButton;
    QPushButton *MainMenuButton;
    QWidget *ServerHostPage;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QPlainTextEdit *ChatBox;
    QGridLayout *gridLayout_3;
    QLineEdit *LowestInput;
    QLineEdit *AmountInput;
    QLineEdit *HighestInput;
    QLabel *LowestLabel;
    QLabel *HighestLabel;
    QLabel *AmountLabel;
    QPushButton *StartGameButton;
    QWidget *ServerClientPage;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *plainTextEdit;
    QLabel *label;
    QGridLayout *gridLayout_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *LowestLabel2;
    QLabel *HighestLabel2;
    QLabel *AmountLabel2;
    QPushButton *ReadyButton;
    QWidget *GamePage;
    QVBoxLayout *verticalLayout_4;
    QLabel *WordLabel;
    QGridLayout *gridLayout_6;
    QPushButton *SkipButton;
    QPushButton *ClearButton;
    QPushButton *EnterButton;
    QLineEdit *UserInput;

    void setupUi(QWidget *MultiPlayerScreen)
    {
        if (MultiPlayerScreen->objectName().isEmpty())
            MultiPlayerScreen->setObjectName(QString::fromUtf8("MultiPlayerScreen"));
        MultiPlayerScreen->resize(600, 600);
        verticalLayout = new QVBoxLayout(MultiPlayerScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(MultiPlayerScreen);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        JoinStartPage = new QWidget();
        JoinStartPage->setObjectName(QString::fromUtf8("JoinStartPage"));
        verticalLayout_2 = new QVBoxLayout(JoinStartPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TitleLabel = new QLabel(JoinStartPage);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setStyleSheet(QString::fromUtf8("font-size: 30px;"));

        verticalLayout_2->addWidget(TitleLabel, 0, Qt::AlignHCenter);

        ErrorLabel = new QLabel(JoinStartPage);
        ErrorLabel->setObjectName(QString::fromUtf8("ErrorLabel"));
        ErrorLabel->setStyleSheet(QString::fromUtf8("font-size: 30px;\n"
"color: rgb(239, 41, 41);"));

        verticalLayout_2->addWidget(ErrorLabel, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        HostInput = new QLineEdit(JoinStartPage);
        HostInput->setObjectName(QString::fromUtf8("HostInput"));

        gridLayout->addWidget(HostInput, 1, 0, 1, 1);

        PortInput = new QLineEdit(JoinStartPage);
        PortInput->setObjectName(QString::fromUtf8("PortInput"));

        gridLayout->addWidget(PortInput, 1, 1, 1, 1);

        label_2 = new QLabel(JoinStartPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        label_3 = new QLabel(JoinStartPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);


        verticalLayout_2->addLayout(gridLayout);

        StartServerButton = new QPushButton(JoinStartPage);
        StartServerButton->setObjectName(QString::fromUtf8("StartServerButton"));

        verticalLayout_2->addWidget(StartServerButton);

        JoinServerButton = new QPushButton(JoinStartPage);
        JoinServerButton->setObjectName(QString::fromUtf8("JoinServerButton"));

        verticalLayout_2->addWidget(JoinServerButton);

        MainMenuButton = new QPushButton(JoinStartPage);
        MainMenuButton->setObjectName(QString::fromUtf8("MainMenuButton"));

        verticalLayout_2->addWidget(MainMenuButton);

        stackedWidget->addWidget(JoinStartPage);
        ServerHostPage = new QWidget();
        ServerHostPage->setObjectName(QString::fromUtf8("ServerHostPage"));
        verticalLayout_3 = new QVBoxLayout(ServerHostPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(ServerHostPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        ChatBox = new QPlainTextEdit(ServerHostPage);
        ChatBox->setObjectName(QString::fromUtf8("ChatBox"));
        ChatBox->setReadOnly(true);

        gridLayout_2->addWidget(ChatBox, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LowestInput = new QLineEdit(ServerHostPage);
        LowestInput->setObjectName(QString::fromUtf8("LowestInput"));

        gridLayout_3->addWidget(LowestInput, 1, 0, 1, 1);

        AmountInput = new QLineEdit(ServerHostPage);
        AmountInput->setObjectName(QString::fromUtf8("AmountInput"));

        gridLayout_3->addWidget(AmountInput, 1, 2, 1, 1);

        HighestInput = new QLineEdit(ServerHostPage);
        HighestInput->setObjectName(QString::fromUtf8("HighestInput"));

        gridLayout_3->addWidget(HighestInput, 1, 1, 1, 1);

        LowestLabel = new QLabel(ServerHostPage);
        LowestLabel->setObjectName(QString::fromUtf8("LowestLabel"));

        gridLayout_3->addWidget(LowestLabel, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        HighestLabel = new QLabel(ServerHostPage);
        HighestLabel->setObjectName(QString::fromUtf8("HighestLabel"));

        gridLayout_3->addWidget(HighestLabel, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        AmountLabel = new QLabel(ServerHostPage);
        AmountLabel->setObjectName(QString::fromUtf8("AmountLabel"));

        gridLayout_3->addWidget(AmountLabel, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        StartGameButton = new QPushButton(ServerHostPage);
        StartGameButton->setObjectName(QString::fromUtf8("StartGameButton"));
        StartGameButton->setEnabled(true);

        gridLayout_3->addWidget(StartGameButton, 2, 0, 1, 3);


        verticalLayout_3->addLayout(gridLayout_3);

        stackedWidget->addWidget(ServerHostPage);
        ServerClientPage = new QWidget();
        ServerClientPage->setObjectName(QString::fromUtf8("ServerClientPage"));
        verticalLayout_6 = new QVBoxLayout(ServerClientPage);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        plainTextEdit = new QPlainTextEdit(ServerClientPage);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout_4->addWidget(plainTextEdit, 0, 1, 1, 1);

        label = new QLabel(ServerClientPage);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 4);

        verticalLayout_6->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lineEdit_2 = new QLineEdit(ServerClientPage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        gridLayout_5->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(ServerClientPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        gridLayout_5->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(ServerClientPage);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        gridLayout_5->addWidget(lineEdit_3, 1, 2, 1, 1);

        LowestLabel2 = new QLabel(ServerClientPage);
        LowestLabel2->setObjectName(QString::fromUtf8("LowestLabel2"));

        gridLayout_5->addWidget(LowestLabel2, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        HighestLabel2 = new QLabel(ServerClientPage);
        HighestLabel2->setObjectName(QString::fromUtf8("HighestLabel2"));

        gridLayout_5->addWidget(HighestLabel2, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        AmountLabel2 = new QLabel(ServerClientPage);
        AmountLabel2->setObjectName(QString::fromUtf8("AmountLabel2"));

        gridLayout_5->addWidget(AmountLabel2, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);

        ReadyButton = new QPushButton(ServerClientPage);
        ReadyButton->setObjectName(QString::fromUtf8("ReadyButton"));

        gridLayout_5->addWidget(ReadyButton, 2, 0, 1, 3);


        verticalLayout_6->addLayout(gridLayout_5);

        stackedWidget->addWidget(ServerClientPage);
        GamePage = new QWidget();
        GamePage->setObjectName(QString::fromUtf8("GamePage"));
        verticalLayout_4 = new QVBoxLayout(GamePage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        WordLabel = new QLabel(GamePage);
        WordLabel->setObjectName(QString::fromUtf8("WordLabel"));
        WordLabel->setStyleSheet(QString::fromUtf8("font-size: 30px;\n"
""));

        verticalLayout_4->addWidget(WordLabel, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        SkipButton = new QPushButton(GamePage);
        SkipButton->setObjectName(QString::fromUtf8("SkipButton"));

        gridLayout_6->addWidget(SkipButton, 1, 1, 1, 1);

        ClearButton = new QPushButton(GamePage);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        gridLayout_6->addWidget(ClearButton, 1, 0, 1, 1);

        EnterButton = new QPushButton(GamePage);
        EnterButton->setObjectName(QString::fromUtf8("EnterButton"));

        gridLayout_6->addWidget(EnterButton, 1, 2, 1, 1);

        UserInput = new QLineEdit(GamePage);
        UserInput->setObjectName(QString::fromUtf8("UserInput"));

        gridLayout_6->addWidget(UserInput, 0, 0, 1, 3);


        verticalLayout_4->addLayout(gridLayout_6);

        stackedWidget->addWidget(GamePage);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(MultiPlayerScreen);

        QMetaObject::connectSlotsByName(MultiPlayerScreen);
    } // setupUi

    void retranslateUi(QWidget *MultiPlayerScreen)
    {
        MultiPlayerScreen->setWindowTitle(QCoreApplication::translate("MultiPlayerScreen", "Form", nullptr));
        TitleLabel->setText(QCoreApplication::translate("MultiPlayerScreen", "Multiplayer", nullptr));
        ErrorLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("MultiPlayerScreen", "Host IP", nullptr));
        label_3->setText(QCoreApplication::translate("MultiPlayerScreen", "Port", nullptr));
        StartServerButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Start Server", nullptr));
        JoinServerButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Join Server", nullptr));
        MainMenuButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Main Menu", nullptr));
        label_4->setText(QCoreApplication::translate("MultiPlayerScreen", "Some Ready shit here", nullptr));
        LowestInput->setText(QCoreApplication::translate("MultiPlayerScreen", "1", nullptr));
        AmountInput->setText(QCoreApplication::translate("MultiPlayerScreen", "10", nullptr));
        HighestInput->setText(QCoreApplication::translate("MultiPlayerScreen", "10", nullptr));
        LowestLabel->setText(QCoreApplication::translate("MultiPlayerScreen", "Lowest", nullptr));
        HighestLabel->setText(QCoreApplication::translate("MultiPlayerScreen", "Highest", nullptr));
        AmountLabel->setText(QCoreApplication::translate("MultiPlayerScreen", "Amount", nullptr));
        StartGameButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Start Game", nullptr));
        label->setText(QCoreApplication::translate("MultiPlayerScreen", "TextLabel", nullptr));
        LowestLabel2->setText(QCoreApplication::translate("MultiPlayerScreen", "Lowest", nullptr));
        HighestLabel2->setText(QCoreApplication::translate("MultiPlayerScreen", "Highest", nullptr));
        AmountLabel2->setText(QCoreApplication::translate("MultiPlayerScreen", "Amount", nullptr));
        ReadyButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Ready", nullptr));
        WordLabel->setText(QString());
        SkipButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Skip", nullptr));
        ClearButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Clear", nullptr));
        EnterButton->setText(QCoreApplication::translate("MultiPlayerScreen", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MultiPlayerScreen: public Ui_MultiPlayerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYERSCREEN_H
