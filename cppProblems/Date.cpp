#include "Date.h"
#include <ctime>

using namespace std;

Date::Date(){
    int totalSeconds = time(0);
    year = 1970 + totalSeconds / 31557600;
    int remainingSeconds = totalSeconds % 31557600;
    month = remainingSeconds / 2628002.88;
    remainingSeconds = remainingSeconds % 2628002.88;
    day = remainingSeconds / 86400;
}
Date::Date(int elapseTime){
    int totalMinutes = elapseTime / 60;
    int totalHours = totalMinutes / 60;
    int totalDays = totalHours / 24;
    day = totalHours % 24;
    int totalMonths = totalDays / 30;
    month = totalMonths % 12;
    year = 1970 + totalMonths / 12;
}
Date::Date(int newYear, int newMonth, int newDay){
    year = newYear;
    month = newMonth;
    day = newDay;
}
int Date::getYear(){
    return year;
}
int Date::getMonth(){
    return month;
}
int Date::getDay(){
    return day;
}
void Date::setDate(int elapseTime){
    int totalMinutes = elapseTime / 60;
    int totalHours = totalMinutes / 60;
    int totalDays = totalHours / 24;
    int elapseDay = totalHours % 24 - day;
    int totalMonths = totalDays / 30;
    int elapseMonth = totalMonths % 12 - month;
    int elapseYear = totalMonths / 12 - year;
    day += elapseDay;
    while (day >= 30){
        month++;
        day /= 30;
    }
    month += elapseMonth;
    while (month >= 12){
        year++;
        month /= 12;
    }
    year += elapseYear;
}
