#include "../include/user.h"
#include <QCryptographicHash>  // For password hashing
#include <QDateTime>          // For time tracking
#include <QTime>              // For check-in cutoff
#include <QtMath>             // For qMax()

User::User(const QString& regNo, const QString& password, const QString& name,
           const QString& department, const QString& hostel, const QString& roomNumber)
    : regNo(regNo), 
      password(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex()),
      name(name),
      department(department),
      hostel(hostel),
      roomNumber(roomNumber),
      totalDues(0.0),
      isMessIn(false)
{
    // Constructor now explicitly hashes the password
}

bool User::verifyPassword(const QString& inputPassword) const {
    QString hashedInput = QCryptographicHash::hash(inputPassword.toUtf8(), QCryptographicHash::Sha256).toHex();
    return hashedInput == password;
}

bool User::messIn() {
    if (QTime::currentTime().hour() >= 18) return false; // 6PM cutoff
    if (isMessIn) return false; // Already checked in
    
    lastMessIn = QDateTime::currentDateTime();
    isMessIn = true;
    return true;
}

bool User::messOut() {
    if (!isMessIn) return false;
    
    // Calculate precise duration (minutes)
    qint64 minutes = qMax(1ll, lastMessIn.secsTo(QDateTime::currentDateTime()) / 60);
    addDues(minutes * 0.5); // 0.5 units per minute
    
    isMessIn = false;
    return true;
}

void User::addDues(double amount) {
    totalDues += amount;
}

void User::clearDues(double amount) {
    totalDues = qMax(0.0, totalDues - amount);
}