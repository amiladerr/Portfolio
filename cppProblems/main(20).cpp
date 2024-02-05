#include <iostream>
#include "Rectangle2D.h"

using namespace std;

int main()
{
    Rectangle2D rect1(2, 2, 5.5, 4.9);
    Rectangle2D rect2(4, 5, 10.5, 3.2);
    Rectangle2D rect3(3, 5, 2.3, 5.4);

    cout << "Area: " << rect1.getArea() << "\nPerimeter: " << rect1.getPerimeter()
         << "\nContains: " << rect1.contains(3, 3) << "\nContains: " << rect1.constains(rect2)
         << "\nOverlaps: " << rect1.overlaps(rect3) << endl;
    return 0;
}
