#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle rectangle1(4, 40);
    Rectangle rectangle2(3.5, 35.9);
    cout << "Rectangle 1 area is " << rectangle1.getArea() << " and perimeter is " << rectangle1.getPerimeter() << endl;
    cout << "Rectangle 2 area is " << rectangle2.getArea() << " and perimeter is " << rectangle2.getPerimeter() << endl;
    return 0;
}
