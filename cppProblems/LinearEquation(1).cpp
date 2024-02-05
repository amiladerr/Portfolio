#include "LinearEquation.h"

using namespace std;

LinearEquation::LinearEquation(double newX1, double newY1, double newX2, double newY2, double newX3, double newY3, double newX4, double newY4){
    x1 = newX1;
    y1 = newY1;
    x2 = newX2;
    y2 = newY2;
    x3 = newX3;
    y3 = newY3;
    x4 = newX4;
    y4 = newY4;
}
double LinearEquation::getX1(){
    return x1;
}
double LinearEquation::getY1(){
    return y1;
}
double LinearEquation::getX2(){
    return x2;
}
double LinearEquation::getY2(){
    return y2;
}
double LinearEquation::getX3(){
    return x3;
}
double LinearEquation::getY3(){
    return y3;
}
double LinearEquation::getX4(){
    return x4;
}
double LinearEquation::getY4(){
    return y4;
}
bool LinearEquation::isSolvable(){
    if (((y1 - y2) * (x4 - x3) + (y3 - y4) * (x1 - x2)) != 0) return true;
    return false;
}
double LinearEquation::getX(){
    return ((x2 * y1 - x1 * y2) * (x4 - x3) + (x4 * y3 - x3 * y4) * (x1 - x2)) / ((y1 - y2) * (x4 - x3) + (y3 - y4) * (x1 - x2));
}
double LinearEquation::getY(){
    return ((y1 - y2) * (x4 * y3 - x3 * y4) - (y3 - y4)*(x2 * y1 - x1 * y2)) / ((y1 - y2) * (x4 - x3) + (y3 - y4) * (x1 - x2));
}

