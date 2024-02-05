#include <iostream>
#include "Circle2D.h"

using namespace std;

int main()
{
    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 5.5);
    Circle2D c3(4, 5, 10.5);
    cout << "Area: " << c1.getArea() << "\nPerimeter: " << c1.getPerimeter() << endl;
    cout << "C1 contains 3,3: " << c1.contains(3, 3) << endl;
    cout << "C1 contains C2: " << c2.contains(c1) << "\nC1 overlaps C3: " << c3.overLaps(c1) << endl;
    return 0;
}
