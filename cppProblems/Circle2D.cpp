#include "Circle2D.h"
#include <cmath>

using namespace std;

Circle2D::Circle2D(){
    x = 0;
    y = 0;
    radius = 1;
}
Circle2D::Circle2D(double x, double y, double radius){
    this->x = x;
    this->y = y;
    this->radius = radius;
}
double Circle2D::getX() const{
    return x;
}
double Circle2D::getY() const{
    return y;
}
double Circle2D::getRadius() const{
    return radius;
}
double Circle2D::getArea() const{
    return pow(radius, 2) * (atan(1) * 4);
}
double Circle2D::getPerimeter() const{
    return 2 * radius * (atan(1) * 4);
}
bool Circle2D::contains(double x2, double y2)const{
    double distance = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    if (distance > radius) return true;
    else return false;
}
bool Circle2D::contains(const Circle2D& circle)const{
    double distance = sqrt(pow(circle.getX() - x, 2) + pow(circle.getY() - y, 2));
    if (distance <= abs(radius - circle.getRadius())) return true;
    else return false;
}
bool Circle2D::overLaps(const Circle2D& circle)const{
    double distance = sqrt(pow(circle.getX() - x, 2) + pow(circle.getY() - y, 2));
    if (distance <= radius + circle.getRadius()) return true;
    else return false;
}
