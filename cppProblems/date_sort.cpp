#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>         // For smart pointers (C++11 or newer)

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
  static int Compare(const Date &d1, const Date &d2);             // static member function...
  friend int CompareDates(const Date &d1, const Date &d2);        // CompareDates is NOT a member function, but a friend!
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

// Date::Compare(d1,d2) returns -1 if d1<d2, 0 if d1==d2, 1 if d1>d2
// d1 and d2 are references to avoid copying during the call!
// (const because Compare will not change d1 and d2)

int Date::Compare(const Date &d1, const Date &d2) {
  if(d1.year < d2.year) return -1;
  else if(d1.year > d2.year) return 1;
  else {
    if(d1.month < d2.month) return -1;
    else if(d1.month > d2.month) return 1;
    else {
      if(d1.day < d2.day) return -1;
      else if(d1.day > d2.day) return 1;
      else return 0;
    }
  }
}

// CompareDates(d1,d2) returns -1 if d1<d2, 0 if d1==d2, 1 if d1>d2
// The same as Date::Compare(d1,d2), but it is ORDINARY function, not a member function!

int CompareDates(const Date &d1, const Date &d2) {
  if(d1.year < d2.year) return -1;
  else if(d1.year > d2.year) return 1;
  else {
    if(d1.month < d2.month) return -1;
    else if(d1.month > d2.month) return 1;
    else {
      if(d1.day < d2.day) return -1;
      else if(d1.day > d2.day) return 1;
      else return 0;
    }
  }
}

void SortDateArray(Date arr[], int n) {
  for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j < n; j++)
      if(Date::Compare(arr[i], arr[j]) > 0)       // or CompareDates(arr[i], arr[j])
        swap(arr[i], arr[j]);                     // This swaps two complete Date objects
}

void SortDateArrayPtr(Date *arr[], int n) {
  for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j < n; j++)
      if(Date::Compare(*arr[i], *arr[j]) > 0)       // or CompareDates(*arr[i], *arr[j])
        swap(arr[i], arr[j]);
}

void SortDateArraySmartPtr(shared_ptr<Date> arr[], int n) {
  for(int i = 0; i < n - 1; i++)
    for(int j = i + 1; j < n; j++)
      if(Date::Compare(*arr[i], *arr[j]) > 0)       // or CompareDates(*arr[i], *arr[j])
        swap(arr[i], arr[j]);
}


int main() {
  Date darr[5] = {Date(1, 5, 2012), Date(4, 11, 2008), Date(21, 4, 2015),
    Date(4, 7, 2015), Date(1, 7, 2015)};
  SortDateArray(darr, 5);
  for(int i = 0; i < 5; i++) {
    darr[i].Display();
    cout << endl;
  }
  cout << endl;

  Date *dparr[5] = {new Date(1, 5, 2012), new Date(4, 11, 2008), new Date(21, 4, 2015),
    new Date(4, 7, 2015), new Date(1, 7, 2015)};
  SortDateArrayPtr(dparr, 5);
  for(int i = 0; i < 5; i++) {
    dparr[i]->Display();
    cout << endl;
  }
  for(int i = 0; i < 5; i++) delete dparr[i];
  cout << endl;

  shared_ptr<Date> dsparr[5] = {make_shared<Date>(1, 5, 2012), make_shared<Date>(4, 11, 2008),
    make_shared<Date>(21, 4, 2015), make_shared<Date>(4, 7, 2015), make_shared<Date>(1, 7, 2015)};
  SortDateArraySmartPtr(dsparr, 5);
  for(int i = 0; i < 5; i++) {
    dsparr[i]->Display();
    cout << endl;
  }

}
