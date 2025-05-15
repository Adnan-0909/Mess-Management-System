#include "../include/student.h"
#include <QDateTime>

Student::Student(const QString& name, const QString& rollNumber, 
                const QString& roomNumber, double initialBalance)
    : name(name)
    , rollNumber(rollNumber)
    , roomNumber(roomNumber)
    , messBalance(initialBalance)
    , mealPlanStatus(true)
{
}

bool Student::rechargeBalance(double amount) {
    if (amount <= 0) {
        return false;
    }
    messBalance += amount;
    return true;
}

bool Student::deductBalance(double amount) {
    if (amount <= 0 || amount > messBalance) {
        return false;
    }
    messBalance -= amount;
    return true;
}

void Student::addMealRecord(const QString& mealType, const QString& date) {
    QString record = QString("%1 - %2").arg(date, mealType);
    mealHistory.push_back(record);
} 