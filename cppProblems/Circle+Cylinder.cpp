#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

double const PI = 4 * atan(1);

class Circle {
  double radius;
  public:
      Circle(double newRadius){ SetRadius(newRadius);}
      void SetRadius(double r);
      double getRadius() const { return radius; }
      double getCircumference() const { return 2 * radius * PI; }
      double getArea() const { return radius * radius * PI; }
      void scale (double scalingFactor);
      void Display();
};
void Circle::SetRadius(double r){
    if (r <= 0) throw domain_error("Radius must be positive!");
    radius = r;

}
void Circle::scale(double scalingFactor){
    if (scalingFactor <= 0) throw domain_error("Scaling factor must be positive!");
    radius *= scalingFactor;
}
void Circle::Display(){
    cout << "Radius of the circle: " << radius
         << "\nCircumference: " << getCircumference()
         << "\nArea: " << getArea() << endl;
}

class Cylinder {
    Circle base;
    double height;
    void setHeight(double newHeight);
public:
    Cylinder(double radius, double newHeight) : base(radius) { setHeight(newHeight); }
    void SetCylinder (double radius, double newHeight);
    double getHeight() const { return height; }
    double getRadius() const { return base.getRadius(); }
    Circle getBase() const { return base; }
    double getArea() const { return 2 * base.getArea() + base.getCircumference() * height; }
    double getVolume () const { return base.getArea() * height; }
    void scale (double scaleBase, double scaleHeight);
    void Display() const;
};

void Cylinder::setHeight(double newHeight){
    if (newHeight <= 0) throw domain_error("Height must be positive!");
    height = newHeight;
}
void Cylinder::SetCylinder(double radius, double newHeight){
    if (radius <= 0 || newHeight <= 0) throw domain_error("Values must be positive!");
    base.SetRadius(radius);
    height = newHeight;
}
void Cylinder::scale(double scaleBase, double scaleHeight){
    if (scaleBase <= 0 || scaleHeight <= 0) throw domain_error("Values must be positive!");
    base.scale(scaleBase);
    height *= scaleHeight;
}
void Cylinder::Display()const {
    cout << "Cylinder: "
         << "\nBase Radius: " << getRadius()
         << "\nHeight: " << getHeight()
         << "\nArea: " << getArea()
         << "\nVolume: " << getVolume() << endl;
}
int main(){
    try {
    Circle c1(5);
    c1.Display();
    cout << c1.getRadius() << " " << c1.getArea() << " " << c1.getCircumference() << endl;
    c1.SetRadius(10);
    c1.scale(2);
    c1.Display();
    Cylinder cl1(10, 30);
    cout << cl1.getRadius() << " " << cl1.getHeight() << " " << cl1.getArea() << " " << cl1.getVolume() << endl;
    cl1.SetCylinder(5, 20);
    cl1.Display();
    cl1.scale(3, 0);
    }
    catch (domain_error e){
        cout << e.what();
    }
    return 0;
}
