#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Date {
  int day, month, year;
public:
  Date() { Set(1, 1, 2000); }                                     // Default (parameterless) constructor
//Date() { day = 1; month = 1; year = 2000; }                     // Alternative (longer, but faster) implementation
  Date(int day, int month, int year) { Set(day, month, year); }   // Constructor with parameters
  bool IsLeapYear(int year);
  int NoOfDays(int month, int year);
  void Set(int day1, int month1, int year1);
  void Display();
  int GetDay() { return day; }
  int GetMonth() { return month; }
  int GetYear() { return year; }
  string GetMonthName();
  void PrettyDisplay();
};

bool Date::IsLeapYear(int year) {
  return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int Date::NoOfDays(int month, int year) {
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

string Date::GetMonthName() {
  string names[12] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
  return names[month - 1];
}

void Date::PrettyDisplay() {
  cout << day << ". " << GetMonthName() << " " << year << ".";  // GetMonthName() here is defacto this->GetMonthName()
}

int main() {
  Date d(1, 4, 2019);
  d.Display();
  cout << endl;
  d.PrettyDisplay();
  cout << endl;
  cout << "Month name: " << d.GetMonthName();
  cout << endl;
  cout << d.NoOfDays(2, 2020) << endl;              // Displays 29 - But d is logically unnecessary!
}
