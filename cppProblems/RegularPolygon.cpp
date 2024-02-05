#include "RegularPolygon.h"
#include <cmath>

using namespace std;

RegularPolygon::RegularPolygon(){
    n = 3;
    side = 1;
    x = 0; y = 0;
}
RegularPolygon::RegularPolygon(int num, double s){
    n = num;
    side = s;
    x = 0;
    y = 0;
}
RegularPolygon::RegularPolygon(int num, double s, double newX, double newY){
    n = num;
    side = s;
    x = newX;
    y = newY;
}
int RegularPolygon::getNumberOfSides() const{
    return n;
}
double RegularPolygon::getSide()const{
    return side;
}
double RegularPolygon::getX() const{
    return x;
}
double RegularPolygon::getY()const{
    return y;
}
void RegularPolygon::setNumberOfSides(int num){
    n = num;
}
void RegularPolygon::setSide(double newSide){
    side = newSide;
}
void RegularPolygon::setX(double newX){
    x = newX;
}
void RegularPolygon::setY(double newY){
    y = newY;
}
double RegularPolygon::getPerimeter()const{
    return n * side;
}
double RegularPolygon::getArea() const{
    return (n * pow(side, 2)) / (4 * tan((atan(1)*4)/n));
}
