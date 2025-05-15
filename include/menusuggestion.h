#ifndef MENUSUGGESTION_H
#define MENUSUGGESTION_H

#include <QString>
#include <QDateTime>
#include <vector>

class MenuSuggestion {
private:
    QString regNo;
    QString suggestion;
    QDateTime timestamp;
    bool isApproved;

public:
    MenuSuggestion(const QString& regNo, const QString& suggestion);

    // Getters
    QString getRegNo() const { return regNo; }
    QString getSuggestion() const { return suggestion; }
    QDateTime getTimestamp() const { return timestamp; }
    bool getIsApproved() const { return isApproved; }

    // Setters
    void setApproved(bool approved) { isApproved = approved; }
};

#endif // MENUSUGGESTION_H 