#ifndef MEAL_H
#define MEAL_H

#include <QString>
#include <QDateTime>
#include <QDate>
#include "student.h"

class Meal {
public:
    enum class MealType {
        Breakfast,
        Lunch,
        Dinner
    };

private:
    MealType type;
    QDateTime timestamp;
    QString studentRollNumber;
    double cost;

public:
    // Constructor
    Meal(MealType type, const QString& studentRollNumber, double cost);

    // Getters
    MealType getType() const { return type; }
    QDateTime getTimestamp() const { return timestamp; }
    QString getStudentRollNumber() const { return studentRollNumber; }
    double getCost() const { return cost; }

    // Static methods
    static QString mealTypeToString(MealType type);
    static MealType stringToMealType(const QString& type);
};

#endif // MEAL_H 