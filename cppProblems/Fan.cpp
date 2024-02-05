#include "Fan.h"

using namespace std;

Fan::Fan(){
    speed = 1;
    on = false;
    radius = 5;
}
int Fan::getSpeed(){
    return speed;
}
bool Fan::getOn(){
    return on;
}
double Fan::getRadius(){
    return radius;
}
void Fan::setSpeed(int s){
    speed = s;
}
void Fan::setOn(bool o){
    on = o;
}
void Fan::setRadius(double r){
    radius = r;
}
