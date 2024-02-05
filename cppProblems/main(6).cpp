#include <iostream>
#include "Fan.h"

using namespace std;

int main()
{
    Fan fan1;
    Fan fan2;
    fan1.setSpeed(3);
    fan1.setOn(true);
    fan1.setRadius(10);
    fan2.setSpeed(2);
    fan2.setOn(false);
    fan2.setRadius(5);
    cout << "Properties of the first fan object:\n- speed: " << fan1.getSpeed() << "\n- on: "
         << fan1.getOn() << "\n- radius: " << fan1.getRadius() << endl;
    cout << "Properties of the second fan object:\n- speed: " << fan2.getSpeed() << "\n- on: "
         << fan2.getOn() << "\n- radius: " << fan2.getRadius() << endl;
    return 0;
}
