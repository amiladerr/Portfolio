#include <iostream>
#include <stdexcept>

using namespace std;

struct Date {
  int day, month, year;
  void Set(int day1, int month1, int year1);
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

void Date::Set(int day, int month, int year) {
  if(year < 1900 || month < 1 || month > 12 || day < 1 || day > NoOfDays(month, year))
    throw range_error("Invalid date");
  this->day = day; this->month = month; this->year = year;   // Note that this->day is the same as (*this).day
}

int main() {
  Date d;
  d.Set(5, 12, 2008);                                    // Try 5 13 2008 instead...
  cout << d.day << "/" << d.month << "/" << d.year;
}

