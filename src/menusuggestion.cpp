#include "../include/menusuggestion.h"

MenuSuggestion::MenuSuggestion(const QString& regNo, const QString& suggestion)
    : regNo(regNo)
    , suggestion(suggestion)
    , timestamp(QDateTime::currentDateTime())
    , isApproved(false)
{
} 