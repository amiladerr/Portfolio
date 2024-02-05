#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

const double PI = 4 * atan(1);

class Circle {
  double r;
public:
  Circle(double r) { SetRadius(r); }
  void SetRadius(double r) {
    if(r < 0) throw domain_error("Radius must not be negative");
    Circle::r = r;
  }
  double GetRadius() const { return r; }
  double GetCircumference() const { return 2 * r * PI; }
  double GetArea() const { return r * r * PI; }
};

class Cylinder {
  Circle base;
  double h;
public:
  Cylinder(Circle b, double h) : base(b) { SetHeight(h); }           // base MUST be initialized using : base(n)...
//Cylinder(double r, double h) : base(Circle(r)) { SetHeight(h); }   // It works, but it is tedious...
  Cylinder(double r, double h) : base(r) { SetHeight(h); }           // It is MUCH better!
  void SetBase(Circle b) { base = b; }
  void SetBaseRadius(double r) { base.SetRadius(r); }                // base.r is private!!!
  void SetHeight(double h) {
    if(h < 0) throw domain_error("Height must not be negative");
    Cylinder::h = h;
  }
  void SetAll(Circle b, double h) { SetBase(b); SetHeight(h); }
  Circle GetBase() const { return base; }
  double GetBaseRadius() const { return base.GetRadius(); }          // base.r is private!!!
  double GetHeight() const { return h; }
  double GetArea() const { return 2 * base.GetArea() + h * base.GetCircumference(); }
  double GetVolume() const { return base.GetArea() * h; }
};

int main() {
  Circle c(5);
  cout << c.GetRadius() << endl;
  cout << c.GetCircumference() << endl;
  cout << c.GetArea() << endl;
  Cylinder cyl(c, 10);
  Cylinder cyl2(Circle(5), 10);
  Cylinder cyl3(5, 10);
}
