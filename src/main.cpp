#include "../include/mainwindow.h"      // Main application window
#include "../include/welcomewindow.h"    // Welcome screen with Register/Log In
#include "../include/logindialog.h"      // Login and registration dialog
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Qt application object (handles event loop)

    // Create and show the welcome screen (with Register and Log In buttons)
    WelcomeWindow* welcome = new WelcomeWindow();
    welcome->show();

    // When Register is clicked, show only the registration dialog
    QObject::connect(welcome, &WelcomeWindow::registerClicked, [welcome]() {
        LoginDialog::showRegistrationDialog(welcome);
    });

    // When Log In is clicked, show the login dialog
    QObject::connect(welcome, &WelcomeWindow::loginClicked, [welcome]() {
        LoginDialog dialog;
        dialog.setWindowTitle("Log In");
        if (dialog.exec() == QDialog::Accepted) { // If login is successful
            User* user = dialog.getCurrentUser();
            if (user) {
                // Create and show the main window for the logged-in user
                MainWindow* window = new MainWindow(user);
                // When the user clicks Sign Out, close main window and show welcome again
                QObject::connect(window->findChild<QPushButton*>("signOutButton"), &QPushButton::clicked, [window, welcome]() {
                    window->close();
                    welcome->show();
                });
                window->show();
                welcome->hide(); // Hide welcome while main window is open
            }
        }
    });

    // Start the Qt event loop (runs until all windows are closed)
    return app.exec();
} 