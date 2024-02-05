#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double PI = 4 * atan(1);

class Figure {          // Abstract type (it is not possible to create objects of type Figure
  string type;
  double x_center, y_center;                // Coordinates of the centre of mass
  double inclination;                       // Angle of inclination
public:
  Figure(string type1, double x, double y, double angle) {
    type = type1; x_center = x; y_center = y; inclination = angle;
  }
  double GetXCenter() const { return x_center; }
  double GetYCenter() const { return y_center; }
  double GetInclination() const { return inclination; }
  string GetType() const { return type; }
  void SetCenter(double x, double y) { x_center = x; y_center = y; }
  void SetInclination(double angle) { inclination = angle; }
  virtual double GetCircumference() const = 0;                      // pure virtual or abstract function
  virtual double GetArea() const = 0;                               // (abstract functions make the class abstract)
  virtual ~Figure() {}
};

class Circle : public Figure {
  double radius;
public:
  Circle(double radius1, double x = 0, double y = 0) :
    Figure("Circle", x, y, 0) {
      radius = radius1;
  }
  double GetRadius() const { return radius; }
  double GetCircumference() const { return 2 * radius * PI; }
  double GetArea() const { return radius * radius * PI; }
};

class Rectangle : public Figure {
  double side_a, side_b;
public:
  Rectangle(double a, double b, double x = 0, double y = 0, double angle = 0) :
    Figure("Rectangle", x, y, angle) {
      side_a = a; side_b = b;
  }
  double GetSideA() const { return side_a; }
  double GetSideB() const { return side_b; }
  double GetCircumference() const { return 2 * (side_a + side_b); }
  double GetArea() const { return side_a * side_b; }
};

class Triangle : public Figure {
  double side_a, side_b, side_c;
public:
  Triangle(double a, double b, double c, double x = 0, double y = 0, double angle = 0) :
    Figure("Triangle", x, y, angle) {
      side_a = a; side_b = b; side_c = c;
  }
  double GetSideA() const { return side_a; }
  double GetSideB() const { return side_b; }
  double GetSideC() const { return side_c; }
  double GetCircumference() const { return side_a + side_b + side_c; }
  double GetArea() const {
    double s = GetCircumference() / 2;
    return sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
  }
};

void DisplayInfo(Figure &f) {
  cout << f.GetType() << " " << f.GetArea() << " " << f.GetXCenter() << " " << f.GetYCenter() << endl;
}

int main() {
  Circle c(5);
  DisplayInfo(c);
  Circle c2(5, 10, 10);
  DisplayInfo(c2);
  cout << c2.GetRadius() << endl;
  Rectangle r(10, 30);
  DisplayInfo(r);
  Figure *f[5];
  f[0] = new Circle(5);
  f[1] = new Rectangle(10, 15);
  f[2] = new Triangle(3, 4, 5);
  f[3] = new Triangle(10, 12, 15);
  f[4] = new Rectangle(3, 2);
  for(int i = 0; i < 5; i++) {
    cout << f[i]->GetType() << ": " << f[i]->GetArea() << endl;
  }
  for(int i = 0; i < 5; i++) delete f[i];
}
