#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>//base dialog class
#include <QMap>//for key value pairs
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }//UI class for Qt designer
QT_END_NAMESPACE

class LoginDialog : public QDialog {//inherits from Qdialog
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    User* getCurrentUser() const { return currentUser; }
    static void showRegistrationDialog(QWidget* parent = nullptr);

private slots:
    void onLoginClicked();//function for login button
    void onRegisterClicked();//function for registration button

private:
    Ui::LoginDialog *ui;
    static QMap<QString, User*> users;//users are set private
    User* currentUser;//pointer to cuurent user

    bool validateRegistration(const QString& regNo, const QString& roomNumber);
    void loadUsers();
    void saveUsers();
};

#endif // LOGINDIALOG_H