#include <iostream>
#include <stdexcept>

using namespace std;

struct Date {
  int day, month, year;
};

bool IsLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int NoOfDays(int month, int year) {
  if(month == 4 || month == 6 || month == 9 || month == 11) return 30;
  else if(month != 2) return 31;
  else if(IsLeapYear(year)) return 29;
  else return 28;
}

void SetDate(Date &date, int day, int month, int year) {
  if(year < 1900 || month < 1 || month > 12 || day < 1 || day > NoOfDays(month, year))
    throw range_error("Invalid date");
  date.day = day; date.month = month; date.year = year;
}

int main() {
  Date d;
  SetDate(d, 5, 13, 2008);                              // Try 5 13 2008 instead...
  cout << d.day << "/" << d.month << "/" << d.year;
}

