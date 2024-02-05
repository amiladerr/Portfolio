#include "LinearEquation.h"

using namespace std;

LinearEquation::LinearEquation(double newA, double newB, double newC, double newD, double newE, double newF){
    a = newA;
    b = newB;
    c = newC;
    d = newD;
    e = newE;
    f = newF;
}
double LinearEquation::getA(){
    return a;
}
double LinearEquation::getB(){
    return b;
}
double LinearEquation::getC(){
    return c;
}
double LinearEquation::getD(){
    return d;
}
double LinearEquation::getE(){
    return e;
}
double LinearEquation::getF(){
    return f;
}
bool LinearEquation::isSolvable(){
    if ((a*d - b*c) != 0) return true;
    return false;
}
double LinearEquation::getX(){
    return (e*d - b*f) / (a*d - b*c);
}
double LinearEquation::getY(){
    return (a*f - e*c) / (a*d - b*c);
}
