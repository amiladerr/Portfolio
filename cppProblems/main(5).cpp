#include <iostream>
#include "MyPoint.h"

using namespace std;

int main()
{
    MyPoint myPoint1;
    MyPoint myPoint2(10, 30.5);
    cout << "Distance between the points (" << myPoint1.getX() << ", " << myPoint1.getY() << ") and ("
         << myPoint2.getX() << ", " << myPoint2.getY() << ") is: " << myPoint1.distance(myPoint1, myPoint2) << endl;
    return 0;
}
