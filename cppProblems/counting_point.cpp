#include <iostream>
#include <cmath>

using namespace std;

class CountingPoint {
  double x, y;
  static int cnt_created, cnt_alive;
public:
  CountingPoint() {
    cout << "Parameterless\n";
    x = 0; y = 0;
    cnt_created++; cnt_alive++;
  }
  CountingPoint(double x, double y) {
    cout << "Two parameters\n";
    SetCartesian(x, y);
    cnt_created++; cnt_alive++;
  }
  CountingPoint(const CountingPoint &p) {                           // Copy constructor!
    cout << "Copycon!\n";
    x = p.x; y = p.y;
    cnt_created++; cnt_alive++;
  }
  ~CountingPoint() { cnt_alive--; cout << "destructor\n"; }                                 // Destructor!
  void SetCartesian(double x1, double y1) { x = x1; y = y1; }
  void SetPolar(double rho, double phi) {
    x = rho * cos(phi); y = rho * sin(phi);
  }
  double GetX() const { return x; }
  double GetY() const { return y; }
  double GetRho() const { return sqrt(x * x + y * y); }
  double GetPhi() const { return atan2(y, x); }
  void SetX(double x1) { x = x1; }
  void SetY(double y1) { y = y1; }
  void SetRho(double rho) { SetPolar(rho, GetPhi()); }
  void SetPhi(double phi) { SetPolar(GetRho(), phi); }
  static int GetCreated() { return cnt_created; }
  static int GetAlive() { return cnt_alive; }
};

int CountingPoint::cnt_created = 0;     // static atributes must be created OUTSIDE of a class definition!
int CountingPoint::cnt_alive = 0;

int main() {
  CountingPoint p1, p2, p3(3, 2);
  {
    CountingPoint p4, p5;
    CountingPoint p6 = p1;
    cout << CountingPoint::GetCreated() << " "
      << CountingPoint::GetAlive() << endl;
  }
  cout << CountingPoint::GetCreated() << " "
    << CountingPoint::GetAlive() << endl;

}
