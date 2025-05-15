#include "../include/welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::WelcomeWindow) {
    ui->setupUi(this);
    connect(ui->registerButton, &QPushButton::clicked, this, &WelcomeWindow::registerClicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &WelcomeWindow::loginClicked);
}

WelcomeWindow::~WelcomeWindow() {
    delete ui;
}

void WelcomeWindow::on_registerButton_clicked() {
    emit registerClicked();
}

void WelcomeWindow::on_loginButton_clicked() {
    emit loginClicked();
} 