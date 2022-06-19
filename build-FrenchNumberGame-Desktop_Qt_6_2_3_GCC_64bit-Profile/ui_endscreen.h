/********************************************************************************
** Form generated from reading UI file 'endscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDSCREEN_H
#define UI_ENDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EndScreen
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *SingleScore;
    QVBoxLayout *verticalLayout_2;
    QLabel *ScoreLabel;
    QGridLayout *gridLayout;
    QPushButton *AgainButton;
    QPushButton *MenuButton;
    QWidget *MultiScore;
    QVBoxLayout *verticalLayout_3;
    QLabel *ScreenLabel;
    QTableWidget *Scoreboard;
    QGridLayout *gridLayout_2;
    QPushButton *MultiMenuButton;
    QPushButton *MultiAgainButton;
    QPushButton *MultiLobbyButton;

    void setupUi(QWidget *EndScreen)
    {
        if (EndScreen->objectName().isEmpty())
            EndScreen->setObjectName(QString::fromUtf8("EndScreen"));
        EndScreen->resize(800, 600);
        verticalLayout = new QVBoxLayout(EndScreen);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(EndScreen);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        SingleScore = new QWidget();
        SingleScore->setObjectName(QString::fromUtf8("SingleScore"));
        verticalLayout_2 = new QVBoxLayout(SingleScore);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ScoreLabel = new QLabel(SingleScore);
        ScoreLabel->setObjectName(QString::fromUtf8("ScoreLabel"));

        verticalLayout_2->addWidget(ScoreLabel, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AgainButton = new QPushButton(SingleScore);
        AgainButton->setObjectName(QString::fromUtf8("AgainButton"));

        gridLayout->addWidget(AgainButton, 0, 0, 1, 1);

        MenuButton = new QPushButton(SingleScore);
        MenuButton->setObjectName(QString::fromUtf8("MenuButton"));

        gridLayout->addWidget(MenuButton, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        stackedWidget->addWidget(SingleScore);
        MultiScore = new QWidget();
        MultiScore->setObjectName(QString::fromUtf8("MultiScore"));
        verticalLayout_3 = new QVBoxLayout(MultiScore);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ScreenLabel = new QLabel(MultiScore);
        ScreenLabel->setObjectName(QString::fromUtf8("ScreenLabel"));
        ScreenLabel->setStyleSheet(QString::fromUtf8("font-size: 30px"));

        verticalLayout_3->addWidget(ScreenLabel, 0, Qt::AlignHCenter);

        Scoreboard = new QTableWidget(MultiScore);
        if (Scoreboard->columnCount() < 3)
            Scoreboard->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Scoreboard->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Scoreboard->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Scoreboard->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        Scoreboard->setObjectName(QString::fromUtf8("Scoreboard"));
        Scoreboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Scoreboard->setShowGrid(true);
        Scoreboard->setGridStyle(Qt::SolidLine);
        Scoreboard->setWordWrap(true);
        Scoreboard->setCornerButtonEnabled(true);
        Scoreboard->horizontalHeader()->setVisible(true);
        Scoreboard->horizontalHeader()->setCascadingSectionResizes(false);
        Scoreboard->horizontalHeader()->setHighlightSections(true);
        Scoreboard->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        Scoreboard->horizontalHeader()->setStretchLastSection(true);
        Scoreboard->verticalHeader()->setVisible(true);
        Scoreboard->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(Scoreboard);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        MultiMenuButton = new QPushButton(MultiScore);
        MultiMenuButton->setObjectName(QString::fromUtf8("MultiMenuButton"));

        gridLayout_2->addWidget(MultiMenuButton, 0, 2, 1, 1);

        MultiAgainButton = new QPushButton(MultiScore);
        MultiAgainButton->setObjectName(QString::fromUtf8("MultiAgainButton"));

        gridLayout_2->addWidget(MultiAgainButton, 0, 0, 1, 1);

        MultiLobbyButton = new QPushButton(MultiScore);
        MultiLobbyButton->setObjectName(QString::fromUtf8("MultiLobbyButton"));

        gridLayout_2->addWidget(MultiLobbyButton, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        stackedWidget->addWidget(MultiScore);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(EndScreen);

        QMetaObject::connectSlotsByName(EndScreen);
    } // setupUi

    void retranslateUi(QWidget *EndScreen)
    {
        EndScreen->setWindowTitle(QCoreApplication::translate("EndScreen", "Form", nullptr));
        ScoreLabel->setText(QString());
        AgainButton->setText(QCoreApplication::translate("EndScreen", "Play Again", nullptr));
        MenuButton->setText(QCoreApplication::translate("EndScreen", "Menu", nullptr));
        ScreenLabel->setText(QCoreApplication::translate("EndScreen", "Scoreboard", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Scoreboard->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EndScreen", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Scoreboard->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EndScreen", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Scoreboard->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EndScreen", "Ready", nullptr));
        MultiMenuButton->setText(QCoreApplication::translate("EndScreen", "Main Menu", nullptr));
        MultiAgainButton->setText(QCoreApplication::translate("EndScreen", "Play Again", nullptr));
        MultiLobbyButton->setText(QCoreApplication::translate("EndScreen", "Lobby", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndScreen: public Ui_EndScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDSCREEN_H
