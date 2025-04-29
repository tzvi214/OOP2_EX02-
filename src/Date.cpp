#include "Date.h"

Date::Date() :Validator<std::string>(getTodayDate()) {}


Date::Date(std::string& date) :Validator<std::string>(date) {}
//------------------------------------------------------

bool Date::isValid() const
{
    return true;
    //---
    const std::string& date = m_validator;


    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;

        if (!isdigit(date[i]))
            return false;
    }

    return true;
}
//------------------------------------------------------
const std::string Date::getTodayDate()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime{};

    if (localtime_s(&localTime, &now) != 0)
    {
        return "";
    }

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d");

    return oss.str();
}
