#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget {
    Q_OBJECT
public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

signals:
    void registerClicked();
    void loginClicked();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H 