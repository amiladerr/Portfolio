#include <iostream>
#include <stdexcept>

using namespace std;

struct Date {
private:
  int day, month, year;
public:
  void Set(int day1, int month1, int year1);
  void Display();
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

void Date::Set(int day1, int month1, int year1) {
  if(year1 < 1900 || month1 < 1 || month1 > 12 || day1 < 1 || day1 > NoOfDays(month1, year1))
    throw range_error("Invalid date");
  this->day = day1; this->month = month1; this->year = year1;   // Note that this->day is the same as (*this).day
}

void Date::Display() {
  cout << day << "/" << month << "/" << year;
}

int main() {
  Date d;
  d.Set(5, 12, 2008);                                    // Try 5 13 2008 instead...
//d.month = 15;                                          // Produces an error...
//cout << d.day << "/" << d.month << "/" << d.year;      // Also produces an error...
  d.Display();
}

