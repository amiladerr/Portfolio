#include "MyPoint.h"
#include <cmath>

using namespace std;

MyPoint::MyPoint(){
    x = 0;
    y = 0;
}
MyPoint::MyPoint(double newX, double newY){
    x = newX;
    y = newY;
}
double MyPoint::getX(){
    return x;
}
double MyPoint::getY(){
    return y;
}
double MyPoint::distance(MyPoint point1, MyPoint point2){
    return sqrt(pow((point2.getX()-point1.getX()),2) + pow((point2.getY()-point1.getY()),2));
}
