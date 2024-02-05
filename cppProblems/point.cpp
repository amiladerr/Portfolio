#include <iostream>
#include <cmath>

using namespace std;

class Point {
  double x, y;
public:
  Point() { x = 0; y = 0; }
  Point(double x, double y) { SetCartesian(x, y); }
  void SetCartesian(double x1, double y1) { x = x1; y = y1; }
  void SetPolar(double rho, double phi) {
    x = rho * cos(phi); y = rho * sin(phi);
  }
  double GetX() { return x; }
  double GetY() { return y; }
  double GetRho() { return sqrt(x * x + y * y); }
  double GetPhi() { return atan2(y, x); }
  void SetX(double x1) { x = x1; }
  void SetY(double y1) { y = y1; }
  void SetRho(double rho) { SetPolar(rho, GetPhi()); }
  void SetPhi(double phi) { SetPolar(GetRho(), phi); }
};

class Point2 {
  double rho, phi;
public:
  Point2() { rho = 0; phi = 0; }
  Point2(double x, double y) { SetCartesian(x, y); }
  void SetCartesian(double x, double y) {
    rho = sqrt(x * x + y * y); phi = atan2(y, x);
  }
  void SetPolar(double rho1, double phi1) { rho = rho1; phi = phi1; }
  double GetX() { return rho * cos(phi); }
  double GetY() { return rho * sin(phi); }
  double GetRho() { return rho; }
  double GetPhi() { return phi; }
  void SetX(double x) { SetCartesian(x, GetY()); }
  void SetY(double y) { SetCartesian(GetX(), y); }
  void SetRho(double rho1) { rho = rho1; }
  void SetPhi(double phi1) { phi = phi1; }
};


int main() {
  const double PI = 3.141592654;
  Point p;
  cout << p.GetX() << " " << p.GetY() << " " << p.GetRho() << " " << p.GetPhi() << endl;
  Point pp(3, 5);
  cout << pp.GetX() << " " << pp.GetY() << " " << pp.GetRho() << " " << pp.GetPhi() << endl;
  cout << "--------\n";
  Point p1, p2;
  p1.SetCartesian(3, 5);
  p2.SetPolar(2, PI / 6);
  cout << p1.GetX() << " " << p1.GetY() << " " << p1.GetRho() << " "
    << p1.GetPhi() << endl;
  cout << p2.GetX() << " " << p2.GetY() << " " << p2.GetRho() << " "
    << p2.GetPhi() << endl;
  cout << "--------\n";
  Point2 p3, p4;
  p3.SetCartesian(3, 5);
  p4.SetPolar(2, PI / 6);
  cout << p3.GetX() << " " << p3.GetY() << " " << p3.GetRho() << " "
    << p3.GetPhi() << endl;
  cout << p4.GetX() << " " << p4.GetY() << " " << p4.GetRho() << " "
    << p4.GetPhi() << endl;
}
