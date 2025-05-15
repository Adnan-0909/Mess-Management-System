#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User {
private:
    QString regNo;
    QString password;
    QString name;
    QString department;
    QString hostel;
    QString roomNumber;
    double totalDues;
    QDateTime lastMessIn;
    bool isMessIn;

public:
    // Constructor
    User(const QString& regNo, const QString& password, const QString& name,
         const QString& department, const QString& hostel, const QString& roomNumber);

    // Getters
    QString getRegNo() const { return regNo; }
    QString getName() const { return name; }
    QString getDepartment() const { return department; }
    QString getHostel() const { return hostel; }
    QString getRoomNumber() const { return roomNumber; }
    double getTotalDues() const { return totalDues; }
    QDateTime getLastMessIn() const { return lastMessIn; }
    bool getIsMessIn() const { return isMessIn; }

    // Authentication
    bool verifyPassword(const QString& inputPassword) const;

    // Mess Management
    bool messIn();
    bool messOut();
    void addDues(double amount);
    void clearDues(double amount);
};

#endif // USER_H 