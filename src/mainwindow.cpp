#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QHeaderView>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPixmap>

MainWindow::MainWindow(User* user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUser(user)
{
    ui->setupUi(this);
    setupUI();
    setupConnections();
    updateMessStatus();
    setLogo("resources/giki_logo.png");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupUI() {
    // Setup menu table
    ui->menuTable->setColumnCount(4);
    ui->menuTable->setHorizontalHeaderLabels(
        {"Day", "Breakfast", "Lunch", "Dinner"});
    ui->menuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Setup mess history table
    ui->messHistoryTable->setColumnCount(3);
    ui->messHistoryTable->setHorizontalHeaderLabels(
        {"Date", "Time", "Status"});
    ui->messHistoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Setup suggestions table
    ui->suggestionsTable->setColumnCount(3);
    ui->suggestionsTable->setHorizontalHeaderLabels(
        {"Date", "Suggestion", "Status"});
    ui->suggestionsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Update total dues
    ui->totalDuesLabel->setText(QString::number(currentUser->getTotalDues(), 'f', 2));

    // Refresh all tables
    refreshMenu();
    refreshMessHistory();
    refreshSuggestions();
}

void MainWindow::setupConnections() {
    // Mess Management
    connect(ui->messInButton, &QPushButton::clicked, this, &MainWindow::onMessInClicked);
    connect(ui->messOutButton, &QPushButton::clicked, this, &MainWindow::onMessOutClicked);
    connect(ui->signOutButton, &QPushButton::clicked, this, &MainWindow::onSignOutClicked);
    
    // Track Record
    connect(ui->printBillButton, &QPushButton::clicked, this, &MainWindow::onPrintBillClicked);
    
    // Menu Suggestions
    connect(ui->submitSuggestionButton, &QPushButton::clicked, this, &MainWindow::onSubmitSuggestionClicked);
}

void MainWindow::onMessInClicked() {
    QTime currentTime = QTime::currentTime();
    QTime cutoffTime(18, 0, 0); // 6:00 PM
    if (currentTime > cutoffTime) {
        QMessageBox::warning(this, "Error", "Cannot mess in after 6 PM!");
        return;
    }
    if (currentUser->messIn()) {
        updateMessStatus();
        refreshMessHistory();
        QMessageBox::information(this, "Success", "Successfully mess in!");
    } else {
        QMessageBox::warning(this, "Error", "Already mess in!");
    }
}

void MainWindow::onMessOutClicked() {
    if (currentUser->messOut()) {
        updateMessStatus();
        refreshMessHistory();
        QMessageBox::information(this, "Success", "Successfully mess out!");
    } else {
        QMessageBox::warning(this, "Error", "Not mess in!");
    }
}

void MainWindow::onSignOutClicked() {
    this->close();
}

void MainWindow::refreshMenu() {
    ui->menuTable->setRowCount(0);
    // Fixed weekly menu
    const QStringList days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const QStringList breakfast = {"Paratha & Chai", "Halwa Puri", "Anda Paratha", "Chana Masala", "Aloo Paratha", "Suji Halwa", "Poori Chana"};
    const QStringList lunch = {"Chicken Biryani", "Daal Chawal", "Qeema", "Biryani", "Chicken Pulao", "Daal Gosht", "Chicken Biryani"};
    const QStringList dinner = {"Nihari", "Karahi", "Chicken Korma", "Haleem", "Kofta", "Karahi", "Nihari"};
    for (int i = 0; i < 7; ++i) {
        int row = ui->menuTable->rowCount();
        ui->menuTable->insertRow(row);
        ui->menuTable->setItem(row, 0, new QTableWidgetItem(days[i]));
        ui->menuTable->setItem(row, 1, new QTableWidgetItem(breakfast[i]));
        ui->menuTable->setItem(row, 2, new QTableWidgetItem(lunch[i]));
        ui->menuTable->setItem(row, 3, new QTableWidgetItem(dinner[i]));
    }
}

void MainWindow::refreshMessHistory() {
    ui->messHistoryTable->setRowCount(0);
    
    // Add mess in/out history
    if (currentUser->getIsMessIn()) {
        int row = ui->messHistoryTable->rowCount();
        ui->messHistoryTable->insertRow(row);
        ui->messHistoryTable->setItem(row, 0, new QTableWidgetItem(currentUser->getLastMessIn().date().toString("yyyy-MM-dd")));
        ui->messHistoryTable->setItem(row, 1, new QTableWidgetItem(currentUser->getLastMessIn().time().toString("hh:mm:ss")));
        ui->messHistoryTable->setItem(row, 2, new QTableWidgetItem("Mess In"));
    }
}

void MainWindow::onPrintBillClicked() {
    printBill();
}

void MainWindow::printBill() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save Bill", "MessBill.txt", "Text Files (*.txt)");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }
    QTextStream out(&file);
    out << "********** Mess Bill **********\n";
    out << "Registration Number: " << currentUser->getRegNo() << "\n";
    out << "Name: " << currentUser->getName() << "\n";
    out << "Department: " << currentUser->getDepartment() << "\n";
    out << "Hostel: " << currentUser->getHostel() << "\n";
    out << "Room Number: " << currentUser->getRoomNumber() << "\n";
    out << "------------------------------\n";
    out << "Total Dues: " << QString::number(currentUser->getTotalDues(), 'f', 2) << "\n";
    out << "------------------------------\n";
    out << "Generated on: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
    out << "******************************\n";
    file.close();
    QMessageBox::information(this, "Success", "Bill saved as text file.");
}

void MainWindow::onSubmitSuggestionClicked() {
    QString suggestion = ui->suggestionInput->toPlainText();
    if (suggestion.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a suggestion.");
        return;
    }

    suggestions.emplace_back(currentUser->getRegNo(), suggestion);
    refreshSuggestions();
    ui->suggestionInput->clear();
    QMessageBox::information(this, "Success", "Suggestion submitted successfully!");
}

void MainWindow::refreshSuggestions() {
    ui->suggestionsTable->setRowCount(0);
    for (const auto& suggestion : suggestions) {
        if (suggestion.getRegNo() == currentUser->getRegNo()) {
            int row = ui->suggestionsTable->rowCount();
            ui->suggestionsTable->insertRow(row);
            ui->suggestionsTable->setItem(row, 0, new QTableWidgetItem(suggestion.getTimestamp().toString("yyyy-MM-dd")));
            ui->suggestionsTable->setItem(row, 1, new QTableWidgetItem(suggestion.getSuggestion()));
            ui->suggestionsTable->setItem(row, 2, new QTableWidgetItem(suggestion.getIsApproved() ? "Approved" : "Pending"));
        }
    }
}

void MainWindow::updateMessStatus() {
    if (currentUser->getIsMessIn()) {
        ui->currentStatusLabel->setText("Mess In");
        ui->lastMessInTimeLabel->setText(currentUser->getLastMessIn().toString("yyyy-MM-dd hh:mm:ss"));
    } else {
        ui->currentStatusLabel->setText("Not Mess In");
        ui->lastMessInTimeLabel->setText("Never");
    }
}

void MainWindow::setLogo(const QString&) {
    // Use Qt resource system for the logo
    QPixmap logoPixmap(":/giki_logo.png");
    if (!logoPixmap.isNull()) {
        ui->logoLabel->setPixmap(logoPixmap.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->logoLabel->setText("");
    } else {
        ui->logoLabel->setText("LOGO HERE");
    }
} 