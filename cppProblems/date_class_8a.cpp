#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Date {
  int day, month, year;
  static bool IsLeapYear(int year);
  static int NoOfDays(int month, int year);
public:
  Date() { Set(1, 1, 2000); }                                     // Default (parameterless) constructor
//Date() { day = 1; month = 1; year = 2000; }                     // Alternative (longer, but faster) implementation
  Date(int day, int month, int year) { Set(day, month, year); }   // Constructor with parameters
  void Set(int day1, int month1, int year1);
  void Display() const;
  int GetDay() const { return day; }
  int GetMonth() const { return month; }
  int GetYear() const { return year; }
  string GetMonthName() const;
  void PrettyDisplay() const;
  void Next();
  void Previous();
  void Advance(int howmuch);
  int DayOfWeek() const;
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

void Date::Display() const {
  cout << day << "/" << month << "/" << year;
}

string Date::GetMonthName() const {
  string names[12] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
  return names[month - 1];
}

void Date::PrettyDisplay() const {
  cout << day << ". " << GetMonthName() << " " << year << ".";  // GetMonthName() here is defacto this->GetMonthName()
}

void Date::Next() {
  day++;
  if(day > NoOfDays(month, year)) {
    day = 1; month++;
  }
  if(month > 12) {
    month = 1; year++;
  }
}

void Date::Previous() {
  day--;
  if(day < 1) {
    month--; day = NoOfDays(month, year);
  }
  if(month < 1) {
    year--; month = 12;
  }
}

// Not very efficient, but it works...

void Date::Advance(int howmuch) {
  if(howmuch > 0)
    for(int i = 1; i <= howmuch; i++) Next();
  else
    for(int i = 1; i <= -howmuch; i++) Previous();
}

// This magic formula is picked from Wikipedia...

int Date::DayOfWeek() const {
  int Y = year, m = month - 2;
  if(month < 3) {
    Y = year - 1; m = month + 10;
  }
  int y = Y % 100, c = Y / 100;
  return 7 + (day + int(2.6 * m - 0.2) + y + y / 4 + c / 4 - 2 * c) % 7;
}

int main() {
  Date d(4, 4, 2019);
  d.Display();
  cout << endl;
  cout << "Today is: " << d.DayOfWeek() << endl;
  d.Set(31, 5, 2019);
  d.Display();
  cout << endl;
  d.Next();
  d.Display();
  cout << endl;
  cout << d.GetDay() << " " << d.GetMonth() << " " << d.GetYear() << endl;
  d.Set(1, 1, 2016);
  d.Previous();
  d.Display();
  cout << endl;
  d.Advance(100);
  d.Display();
  cout << endl;
  d.Advance(-50);       // Go back...
  d.Display();
  cout << endl;
  const Date d2(1, 5, 2019);
//d2.Set(5, 8, 2020);               // can't - d2 is const
//d2.Next();                        // can't - d2 is const
  d2.Display();                     // but it can - Display() is const!
  cout << endl;
  Date dd[3] = {Date(15, 12, 2012), Date(22, 7, 2017), Date(5, 12, 2023)};
  for(int i = 0; i < 3; i++) {
    dd[i].Display();
    cout << endl;
  }


}
