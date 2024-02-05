#include <iostream>
#include "LinearEquation.h"

using namespace std;

int main()
{
    double a, b, c, d, e, f;
    cout << "Enter 6 values: ";
    cin >> a >> b >> c >> d >> e >> f;
    LinearEquation equation(a, b, c, d, e, f);
    if (!equation.isSolvable()) cout << "The equation has no solution." << endl;
    else cout << "x = " << equation.getX() << "\ny = " << equation.getY() << endl;
    return 0;
}
