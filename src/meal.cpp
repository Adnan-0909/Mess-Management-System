#include "../include/meal.h"

Meal::Meal(MealType type, const QString& studentRollNumber, double cost)
    : type(type)
    , timestamp(QDateTime::currentDateTime())
    , studentRollNumber(studentRollNumber)
    , cost(cost)
{
}

QString Meal::mealTypeToString(MealType type) {
    switch (type) {
        case MealType::Breakfast:
            return "Breakfast";
        case MealType::Lunch:
            return "Lunch";
        case MealType::Dinner:
            return "Dinner";
        default:
            return "Unknown";
    }
}

Meal::MealType Meal::stringToMealType(const QString& type) {
    if (type == "Breakfast") return MealType::Breakfast;
    if (type == "Lunch") return MealType::Lunch;
    if (type == "Dinner") return MealType::Dinner;
    return MealType::Breakfast; // Default value
} 