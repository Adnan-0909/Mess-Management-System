#include "../include/logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QInputDialog>

QMap<QString, User*> LoginDialog::users; // Static user map definition

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , currentUser(nullptr)
{
    ui->setupUi(this);
    loadUsers();

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);//slots, Qt functions
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);
}

LoginDialog::~LoginDialog() {
    saveUsers();
    delete ui;
}

void LoginDialog::onLoginClicked() {
    QString regNo = ui->regNoInput->text();
    QString password = ui->passwordInput->text();

    if (regNo.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all fields.");
        return;
    }

    if (!users.contains(regNo)) {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    User* user = users[regNo];
    if (!user->verifyPassword(password)) {
        QMessageBox::warning(this, "Error", "Invalid password.");
        return;
    }

    currentUser = user;
    accept();
}

void LoginDialog::onRegisterClicked() {
    bool ok;
    QString regNo = QInputDialog::getText(this, "Registration", 
                                        "Enter Registration Number:", 
                                        QLineEdit::Normal, "", &ok);
    if (!ok || regNo.isEmpty()) return;

    if (users.contains(regNo)) {
        QMessageBox::warning(this, "Error", "Registration number already exists.");
        return;
    }

    QString password = QInputDialog::getText(this, "Registration", 
                                           "Enter Password:", 
                                           QLineEdit::Password, "", &ok);
    if (!ok || password.isEmpty()) return;

    QString confirmPassword = QInputDialog::getText(this, "Registration", 
                                                  "Confirm Password:", 
                                                  QLineEdit::Password, "", &ok);
    if (!ok || confirmPassword.isEmpty()) return;

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    QString name = QInputDialog::getText(this, "Registration", 
                                       "Enter Name:", 
                                       QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    QString department = QInputDialog::getText(this, "Registration", 
                                             "Enter Department:", 
                                             QLineEdit::Normal, "", &ok);
    if (!ok || department.isEmpty()) return;

    QString hostel = QInputDialog::getText(this, "Registration", 
                                         "Enter Hostel:", 
                                         QLineEdit::Normal, "", &ok);
    if (!ok || hostel.isEmpty()) return;

    QString roomNumber = QInputDialog::getText(this, "Registration", 
                                             "Enter Room Number:", 
                                             QLineEdit::Normal, "", &ok);
    if (!ok || roomNumber.isEmpty()) return;

    if (!validateRegistration(regNo, roomNumber)) {
        QMessageBox::warning(this, "Error", "Invalid registration number or room number.");
        return;
    }

    User* newUser = new User(regNo, password, name, department, hostel, roomNumber);
    users[regNo] = newUser;
    saveUsers();

    QMessageBox::information(this, "Success", "Registration successful!");
}

bool LoginDialog::validateRegistration(const QString& regNo, const QString& roomNumber) {
    // Check if registration number is unique
    if (users.contains(regNo)) {
        return false;
    }

    // Check if room number is unique
    for (const auto& user : users) {
        if (user->getRoomNumber() == roomNumber) {
            return false;
        }
    }

    return true;
}

void LoginDialog::loadUsers() {
    // TODO: Implement loading users from file
}

void LoginDialog::saveUsers() {
    // TODO: Implement saving users to file
}

void LoginDialog::showRegistrationDialog(QWidget* parent) {
    LoginDialog dialog(parent);
    dialog.setWindowTitle("Register");
    dialog.onRegisterClicked();
} 