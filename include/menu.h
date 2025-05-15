#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QDate>
#include <map>

class Menu {
private:
    struct DailyMenu {
        QString breakfast;
        QString lunch;
        QString dinner;
    };

    std::map<QDate, DailyMenu> menuSchedule;

public:
    // Constructor
    Menu() = default;

    // Methods
    void setDailyMenu(const QDate& date, 
                     const QString& breakfast,
                     const QString& lunch,
                     const QString& dinner);
    
    DailyMenu getDailyMenu(const QDate& date) const;
    
    bool hasMenuForDate(const QDate& date) const;
    
    void removeMenu(const QDate& date);
    
    // Get menu for a specific meal type
    QString getBreakfast(const QDate& date) const;
    QString getLunch(const QDate& date) const;
    QString getDinner(const QDate& date) const;
};

#endif // MENU_H 