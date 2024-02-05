#include <iostream>
#include <stdexcept>

using namespace std;

class Date {
  int day, month, year;
public:
  Date() { Set(1, 1, 2000); }                                     // Default (parameterless) constructor
//Date() { day = 1; month = 1; year = 2000; }                     // Alternative (longer, but faster) implementation
  Date(int day, int month, int year) { Set(day, month, year); }   // Constructor with parameters
  void Set(int day1, int month1, int year1);
  void Display();
  int GetDay() { return day; }
  int GetMonth() { return month; }
  int GetYear() { return year; }
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

void DisplayInfo(Date d) {                      // This is an ordinary function, not a member of class Date!
  cout << "Day is " << d.GetDay() << endl;
  cout << "Month is " << d.GetMonth() << endl;
  cout << "Year is " << d.GetYear() << endl;
}

int main() {
  Date d;                           // Will be set to 1/1/2000 via default constructor
  d.Display();                      //   (but it will produce an error if the default constructor is removed)
  cout << endl;
  d.Set(5, 2, 2013);
  d.Display();
  cout << endl;
  Date d2(29, 3, 2019);
  d2.Display();
  cout << endl;
  d2 = Date(1, 4, 2019);            // Explicit call of constructor!
  d2 = {1, 4, 2019};                // Shortcut - only starting from C++11
  d2.Display();
  cout << endl;
  DisplayInfo(d2);
  DisplayInfo(Date(23, 5, 2020));   // Temporary date 23/5/2020 is sent...
  DisplayInfo({23, 5, 2020});       // Shortcut - only starting from C++11
}
