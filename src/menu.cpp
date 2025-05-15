#include "../include/menu.h"

void Menu::setDailyMenu(const QDate& date, 
                       const QString& breakfast,
                       const QString& lunch,
                       const QString& dinner) {
    DailyMenu menu;
    menu.breakfast = breakfast;
    menu.lunch = lunch;
    menu.dinner = dinner;
    menuSchedule[date] = menu;
}

Menu::DailyMenu Menu::getDailyMenu(const QDate& date) const {
    if (hasMenuForDate(date)) {
        return menuSchedule.at(date);
    }
    return DailyMenu{"No menu set", "No menu set", "No menu set"};
}

bool Menu::hasMenuForDate(const QDate& date) const {
    return menuSchedule.find(date) != menuSchedule.end();
}

void Menu::removeMenu(const QDate& date) {
    menuSchedule.erase(date);
}

QString Menu::getBreakfast(const QDate& date) const {
    return getDailyMenu(date).breakfast;
}

QString Menu::getLunch(const QDate& date) const {
    return getDailyMenu(date).lunch;
}

QString Menu::getDinner(const QDate& date) const {
    return getDailyMenu(date).dinner;
} 