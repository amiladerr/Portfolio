#include <iostream>
#include "LinearEquation.h"

using namespace std;

int main()
{
    cout << "Enter four coordinates: ";
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    LinearEquation equation (x1, y1, x2, y2, x3, y3, x4, y4);
    if (!equation.isSolvable()) cout << "There is no intersecting point." << endl;
    else cout << "Intersecting point is at (" << equation.getX() << ", " << equation.getY() << ")" << endl;
    return 0;
}
