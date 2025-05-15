#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <QString>

class Student {
private:
    QString name;
    QString rollNumber;
    QString roomNumber;
    double messBalance;
    bool mealPlanStatus;
    std::vector<QString> mealHistory;

public:
    // Constructor
    Student(const QString& name, const QString& rollNumber, 
            const QString& roomNumber, double initialBalance = 0.0);

    // Getters
    QString getName() const { return name; }
    QString getRollNumber() const { return rollNumber; }
    QString getRoomNumber() const { return roomNumber; }
    double getMessBalance() const { return messBalance; }
    bool getMealPlanStatus() const { return mealPlanStatus; }
    const std::vector<QString>& getMealHistory() const { return mealHistory; }

    // Setters
    void setName(const QString& newName) { name = newName; }
    void setRoomNumber(const QString& newRoom) { roomNumber = newRoom; }
    void setMealPlanStatus(bool status) { mealPlanStatus = status; }

    // Methods
    bool rechargeBalance(double amount);
    bool deductBalance(double amount);
    void addMealRecord(const QString& mealType, const QString& date);
};

#endif // STUDENT_H 