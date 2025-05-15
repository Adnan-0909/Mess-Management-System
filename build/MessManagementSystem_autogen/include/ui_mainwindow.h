/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QPushButton *signOutButton;
    QTabWidget *tabWidget;
    QWidget *messTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *messStatusGroup;
    QFormLayout *formLayout;
    QLabel *statusLabel;
    QLabel *currentStatusLabel;
    QLabel *lastMessInLabel;
    QLabel *lastMessInTimeLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *messInButton;
    QPushButton *messOutButton;
    QWidget *menuTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *menuTable;
    QWidget *trackTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *duesGroup;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *totalDuesLabel;
    QTableWidget *messHistoryTable;
    QPushButton *printBillButton;
    QWidget *suggestionsTab;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *suggestionGroup;
    QVBoxLayout *verticalLayout_6;
    QTextEdit *suggestionInput;
    QPushButton *submitSuggestionButton;
    QTableWidget *suggestionsTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        logoLabel = new QLabel(centralwidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        signOutButton = new QPushButton(centralwidget);
        signOutButton->setObjectName("signOutButton");

        verticalLayout->addWidget(signOutButton);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        messTab = new QWidget();
        messTab->setObjectName("messTab");
        verticalLayout_2 = new QVBoxLayout(messTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        messStatusGroup = new QGroupBox(messTab);
        messStatusGroup->setObjectName("messStatusGroup");
        formLayout = new QFormLayout(messStatusGroup);
        formLayout->setObjectName("formLayout");
        statusLabel = new QLabel(messStatusGroup);
        statusLabel->setObjectName("statusLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, statusLabel);

        currentStatusLabel = new QLabel(messStatusGroup);
        currentStatusLabel->setObjectName("currentStatusLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, currentStatusLabel);

        lastMessInLabel = new QLabel(messStatusGroup);
        lastMessInLabel->setObjectName("lastMessInLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, lastMessInLabel);

        lastMessInTimeLabel = new QLabel(messStatusGroup);
        lastMessInTimeLabel->setObjectName("lastMessInTimeLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lastMessInTimeLabel);


        verticalLayout_2->addWidget(messStatusGroup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        messInButton = new QPushButton(messTab);
        messInButton->setObjectName("messInButton");

        horizontalLayout->addWidget(messInButton);

        messOutButton = new QPushButton(messTab);
        messOutButton->setObjectName("messOutButton");

        horizontalLayout->addWidget(messOutButton);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(messTab, QString());
        menuTab = new QWidget();
        menuTab->setObjectName("menuTab");
        verticalLayout_3 = new QVBoxLayout(menuTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        menuTable = new QTableWidget(menuTab);
        menuTable->setObjectName("menuTable");

        verticalLayout_3->addWidget(menuTable);

        tabWidget->addTab(menuTab, QString());
        trackTab = new QWidget();
        trackTab->setObjectName("trackTab");
        verticalLayout_4 = new QVBoxLayout(trackTab);
        verticalLayout_4->setObjectName("verticalLayout_4");
        duesGroup = new QGroupBox(trackTab);
        duesGroup->setObjectName("duesGroup");
        formLayout_2 = new QFormLayout(duesGroup);
        formLayout_2->setObjectName("formLayout_2");
        label = new QLabel(duesGroup);
        label->setObjectName("label");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        totalDuesLabel = new QLabel(duesGroup);
        totalDuesLabel->setObjectName("totalDuesLabel");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, totalDuesLabel);


        verticalLayout_4->addWidget(duesGroup);

        messHistoryTable = new QTableWidget(trackTab);
        messHistoryTable->setObjectName("messHistoryTable");

        verticalLayout_4->addWidget(messHistoryTable);

        printBillButton = new QPushButton(trackTab);
        printBillButton->setObjectName("printBillButton");

        verticalLayout_4->addWidget(printBillButton);

        tabWidget->addTab(trackTab, QString());
        suggestionsTab = new QWidget();
        suggestionsTab->setObjectName("suggestionsTab");
        verticalLayout_5 = new QVBoxLayout(suggestionsTab);
        verticalLayout_5->setObjectName("verticalLayout_5");
        suggestionGroup = new QGroupBox(suggestionsTab);
        suggestionGroup->setObjectName("suggestionGroup");
        verticalLayout_6 = new QVBoxLayout(suggestionGroup);
        verticalLayout_6->setObjectName("verticalLayout_6");
        suggestionInput = new QTextEdit(suggestionGroup);
        suggestionInput->setObjectName("suggestionInput");

        verticalLayout_6->addWidget(suggestionInput);

        submitSuggestionButton = new QPushButton(suggestionGroup);
        submitSuggestionButton->setObjectName("submitSuggestionButton");

        verticalLayout_6->addWidget(submitSuggestionButton);


        verticalLayout_5->addWidget(suggestionGroup);

        suggestionsTable = new QTableWidget(suggestionsTab);
        suggestionsTable->setObjectName("suggestionsTable");

        verticalLayout_5->addWidget(suggestionsTable);

        tabWidget->addTab(suggestionsTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mess Management System", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "LOGO HERE", nullptr));
        signOutButton->setText(QCoreApplication::translate("MainWindow", "Sign Out", nullptr));
        messStatusGroup->setTitle(QCoreApplication::translate("MainWindow", "Mess Status", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Current Status:", nullptr));
        currentStatusLabel->setText(QCoreApplication::translate("MainWindow", "Not Messed In", nullptr));
        lastMessInLabel->setText(QCoreApplication::translate("MainWindow", "Last Mess In:", nullptr));
        lastMessInTimeLabel->setText(QCoreApplication::translate("MainWindow", "Never", nullptr));
        messInButton->setText(QCoreApplication::translate("MainWindow", "Mess In", nullptr));
        messOutButton->setText(QCoreApplication::translate("MainWindow", "Mess Out", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(messTab), QCoreApplication::translate("MainWindow", "Mess In/Out", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(menuTab), QCoreApplication::translate("MainWindow", "Menu", nullptr));
        duesGroup->setTitle(QCoreApplication::translate("MainWindow", "Current Dues", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total Dues:", nullptr));
        totalDuesLabel->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        printBillButton->setText(QCoreApplication::translate("MainWindow", "Print Bill", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(trackTab), QCoreApplication::translate("MainWindow", "Track Record", nullptr));
        suggestionGroup->setTitle(QCoreApplication::translate("MainWindow", "Add Suggestion", nullptr));
        submitSuggestionButton->setText(QCoreApplication::translate("MainWindow", "Submit Suggestion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(suggestionsTab), QCoreApplication::translate("MainWindow", "Menu Suggestions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
