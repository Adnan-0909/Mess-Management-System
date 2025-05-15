#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <vector>
#include "user.h"
#include "menu.h"
#include "menusuggestion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(User* user, QWidget *parent = nullptr);
    ~MainWindow();

private slots://Event handlers
    // Mess Management
    void onMessInClicked();
    void onMessOutClicked();
    void onSignOutClicked();

    // Menu Management
    void refreshMenu();

    // Track Record
    void refreshMessHistory();
    void onPrintBillClicked();

    // Menu Suggestions
    void onSubmitSuggestionClicked();
    void refreshSuggestions();

private:
    Ui::MainWindow *ui;
    User* currentUser;
    Menu menu;
    std::vector<MenuSuggestion> suggestions;

    // Helper functions
    void setupUI();
    void setupConnections();
    void updateMessStatus();
    void printBill();
    void setLogo(const QString& imagePath);
};

#endif // MAINWINDOW_H 