#include <iostream>
#include "RegularPolygon.h"

using namespace std;

int main()
{
    RegularPolygon object1;
    RegularPolygon object2(6, 4);
    RegularPolygon object3(10, 4, 5.6, 7.8);
    cout << "1: " << object1.getPerimeter() << " " << object1.getArea() << endl
         << "2: " << object2.getPerimeter() << " " << object2.getArea() << endl
         << "3: " << object3.getPerimeter() << " " << object3.getArea() << endl;
    return 0;
}
