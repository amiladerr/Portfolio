#include "QuadraticEquation.h"
#include <cmath>

using namespace std;

QuadraticEquation::QuadraticEquation(double newA, double newB, double newC){
    a = newA;
    b = newB;
    c = newC;
}
double QuadraticEquation::getA(){
    return a;
}
double QuadraticEquation::getB(){
    return b;
}
double QuadraticEquation::getC(){
    return c;
}
double QuadraticEquation::getDiscriminant(){
    return pow(b,2) - 4 * a * c;
}
double QuadraticEquation::getRoot1(){
    if (getDiscriminant() >= 0) return (-b + sqrt(getDiscriminant())) / (2 * a);
    else return 0;
}
double QuadraticEquation::getRoot2(){
    if (getDiscriminant() >= 0) return (-b - sqrt(getDiscriminant())) / (2 * a);
    else return 0;
}
