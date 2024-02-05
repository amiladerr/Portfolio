#include <iostream>

using namespace std;

class Time {
  int h, m, s;
public:
  Time() { h = 0; m = 0; s = 0; }
  Time(int h, int m, int s) { SetTime(h, m, s); }
  void SetTime(int h1, int m1, int s1);
  int GetHours() const { return h; }
  int GetMinutes() const { return m; }
  int GetSeconds() const { return s; }
  Time operator+(Time t2);
  Time &operator+=(Time t2);             // returning reference suppress copying...
  Time &operator++();
  Time operator++(int);                  // To support postfix ++
  Time &operator--();
  Time operator--(int);                  // To support postfix --
  friend ostream &operator<<(ostream &mystream, Time t);
};

void Time::SetTime(int h1, int m1, int s1) {
  while(s1 >= 60) { s1 -= 60; m1++; }
  while(s1 < 0) { s1 += 60; m1--; }
  while(m1 >= 60) { m1 -= 60; h1++; }
  while(m1 < 0) { m1 += 60; h1--; }
  while(h1 >= 24) h1 -= 24;
  while(h1 < 0) h1 += 24;
  h = h1; m = m1; s = s1;
}

ostream &operator<<(ostream &mystream, Time t) {
  if(t.h < 10) mystream << "0";
  mystream << t.h << ":" ;
  if(t.m < 10) mystream << "0";
  mystream << t.m << ":";
  if(t.s < 10) mystream << "0";
  mystream << t.s;
  return mystream;
}

Time Time::operator +(Time t2) {
  return Time(h + t2.h, m + t2.m, s + t2.s);
}

Time &Time::operator +=(Time t2) {
  SetTime(h + t2.h, m + t2.m, s + t2.s);
  return *this;
}

Time &Time::operator++() {
  SetTime(h, m, s + 1);
  return *this;
}

Time Time::operator++(int) {
  Time old(*this);
  SetTime(h, m, s + 1);
  return old;                                   // Returns the old value!
}

Time &Time::operator--() {
  SetTime(h, m, s - 1);
  return *this;
}

Time Time::operator--(int) {
  Time old(*this);
  SetTime(h, m, s - 1);
  return old;                                   // Returns the old value!
}

int main() {
  Time t1(7, 25, 47), t2(5, 43, 29);
  Time t3 = t1 + t2;
  cout << t3 << endl;
  t1 = ++t3;                // This syntax i supported too!
  t1 = t3++;
  ++t3;
  t3 += t2;
  cout << t3 << endl;
  --t3;
  cout << t3 << endl;
}
