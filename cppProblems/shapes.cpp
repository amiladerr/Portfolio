#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 4 * atan(1);

class Shape {
  string color;
public:                                             // Always declare virtual descructor in base class
  virtual ~Shape() {}                               // if you want to use polymorphism
  Shape(string color1) { color = color1; }          // (this will prevent some memory leaks)
  string GetColor() const { return color; }
  virtual string GetType() const { return "Some geometric shape"; }
  virtual double GetArea() const = 0;
  virtual double GetCircumference() const = 0;      // GetArea and GetCircumference are abstract
  void DisplayBasicInfo() {
    cout << "Type: " << GetType() << endl;          // This call will produce unexpected results if
    cout << "Color: " << GetColor() << endl;        // GetType is not virutal
    cout << "Area: " << GetArea() << endl;
    cout << "Circumference: " << GetCircumference() << endl;
  }
  virtual void Display() {
    DisplayBasicInfo();
  }
};

class Circle : public Shape {
  double r;
public:
  Circle(string color1, double r1) : Shape(color1) { r = r1; }
  double GetRadius() const { return r; }
  string GetType() const { return "Circle"; }
  double GetArea() const { return r * r * PI; }
  double GetCircumference() const { return 2 * PI * r; }
  void Display() {
    DisplayBasicInfo();
    cout << "Radius: " << r << endl;
  }
};

class Rectangle : public Shape {
  double a, b;
public:
  Rectangle(string color1, double a1, double b1) : Shape(color1) {
    a = a1; b = b1;
  }
  double GetA() const { return a; }
  double GetB() const { return b; }
  string GetType() const { return "Rectangle"; }
  double GetArea() const { return a * b; }
  double GetCircumference() const { return 2 * (a + b); }
  void Display() {
    DisplayBasicInfo();
    cout << "Side A: " << GetA() << endl;
    cout << "Side B: " << GetB() << endl;
  }
};

/*

This is COMPLETELY WRONG inheritance (improper inheritance)
because Triangle is NOT a special case of Rectangle!

It works, but it is LOGICALLY incorrect!

class Triangle : public Rectangle {
  double c;
public:
  Triangle(string color1, double a1, double b1, double c1)
    : Rectangle(color1, a1, b1) { c = c1; }
    }
  double GetC() const { return c; }
  string GetType() const { return "Triangle"; }
  double GetArea() const {
    double s = GetCircumference() / 2;
    return sqrt(s * (s - GetA()) * (s - GetB()) * (s - c));
  }
  double GetCircumference() const { return GetA() + GetB() + c; }
  void Display() {
    DisplayBasicInfo();
    cout << "Side A: " << GetA() << endl;
    cout << "Side B: " << GetB() << endl;
    cout << "Side C: " << GetC() << endl;
  }
};

*/

class Triangle : public Shape {
  double a, b, c;
public:
  Triangle(string color1, double a1, double b1, double c1) : Shape(color1) {
    a = a1; b = b1; c = c1;
  }
  double GetA() const { return a; }
  double GetB() const { return b; }
  double GetC() const { return c; }
  string GetType() const { return "Triangle"; }
  double GetArea() const {
    double s = GetCircumference() / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }
  double GetCircumference() const { return a + b + c; }
  void Display() {
    DisplayBasicInfo();
    cout << "Side A: " << GetA() << endl;
    cout << "Side B: " << GetB() << endl;
    cout << "Side C: " << GetC() << endl;
  }
};

int main() {
//  Shape ppp("blue");  // Not possible because Shape is abstract

  Shape *s;
  s = new Circle("Blue", 5);
  s->Display();
  cout << s->GetArea() << endl;
  delete s;
  s = new Triangle("Green", 3, 4, 5);
  s->Display();
  cout << s->GetArea() << endl;
  delete s;
  cout << endl << endl;
  Shape *shapes[5];
  shapes[0] = new Circle("Brown", 3);
  shapes[1] = new Rectangle("Black", 3, 5);
  shapes[2] = new Circle("White", 10);
  shapes[3] = new Triangle("Magenta", 4, 7, 8);
  shapes[4] = new Rectangle("Yellow", 15, 8);
  for(int i = 0; i < 5; i++) {
    shapes[i]->Display();
    cout << endl;
  }
  for(int i = 0; i < 5; i++) delete shapes[i];
}
