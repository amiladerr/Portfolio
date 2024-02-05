#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GeometricShape{
    string color;
public:
    GeometricShape(string newColor){ color = newColor; }
    ~GeometricShape() {}
    string getColor() const{ return color; }
    virtual string getTypeOfShape() const { return "Some geometric shape"; }
    virtual double getArea() const = 0;
    virtual double getCircumference() const = 0;
    void DisplayBasicInfo() const;
    virtual void Display() const{
        DisplayBasicInfo();
    }
};

void GeometricShape::DisplayBasicInfo() const{
    cout << "Type: " << getTypeOfShape() << endl
         << "Color: " << getColor() << endl
         << "Area: " << getArea() << endl
         << "Circumference: " << getCircumference() << endl;
}

class Circle : public GeometricShape{
    double radius;
public:
    Circle(string color, double newRadius) : GeometricShape(color) {
        setRadius(newRadius);
    }
    void setRadius (double r) {
        if (r <= 0) throw "Radius must be positive!";
        radius = r;
    }
    double getRadius() const{ return radius; }
    string getTypeOfShape() const { return "Circle"; }
    double getArea() const { return radius * radius * 3.14; }
    double getCircumference() const { return 2 * radius * 3.14; }
    void Display() const {
        DisplayBasicInfo();
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public GeometricShape{
    double a, b;
public:
    Rectangle(string color, double a, double b) : GeometricShape(color){ setRectangle(a, b); }
    void setRectangle(double a, double b){
        if (a <= 0 || b <= 0) throw "Both sides must be positive!";
        this->a = a; this->b = b;
    }
    double getA() const{ return a; }
    double getB() const{ return b; }
    string getTypeOfShape() const { return "Rectangle"; }
    double getArea() const { return a * b; }
    double getCircumference() const { return 2 *(a + b); }
    void Display() const {
        DisplayBasicInfo();
        cout << "Side A: " << a << endl
             << "Side B: " << b << endl;
    }
};

class Triangle : public GeometricShape{
    double a, b, c;
public:
    Triangle(string color, double a, double b, double c) : GeometricShape(color){ setTriangle(a, b, c); }
    void setTriangle(double a, double b, double c){
        if (a <= 0 || b <= 0 || c <= 0 || a+b <= c || a+c <= b || b+c <= a) throw "Sides must be positive!";
        this->a = a; this->b = b; this->c = c;
    }
    double getA() const{ return a; }
    double getB() const{ return b; }
    double getC() const{ return c; }
    string getTypeOfShape() const { return "Triangle"; }
    double getArea() const {
        double s = getCircumference() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double getCircumference() const { return a + b + c; }
    void Display() const {
        DisplayBasicInfo();
        cout << "Side A: " << a << endl
             << "Side B: " << b << endl
             << "Side C: " << c << endl;
    }
};
int main(){
    GeometricShape *shape[5];
    shape[0] = new Circle("Blue", 2.3);
    shape[1] = new Rectangle("Purple", 2, 4);
    shape[2] = new Triangle("Black", 3, 4, 5);
    shape[3] = new Circle("Brown", 5);
    shape[4] = new Rectangle("Pink", 6, 7);
    for (int i = 0; i < 5; i++){
        shape[i]->Display();
        cout << endl;
    }

    for (int i = 0; i < 5; i++) delete shape[i];

return 0;
}
