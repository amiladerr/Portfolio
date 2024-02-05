#include <iostream>
#include "QuadraticEquation.h"

using namespace std;

int main()
{
    double a, b, c;
    cout << "Enter values a, b and c: ";
    cin >> a >> b >> c;
    QuadraticEquation user(a, b, c);
    if (user.getDiscriminant() > 0) cout << "Roots are: x1 = " << user.getRoot1() << ", x2 = " << user.getRoot2() << endl;
    else if (user.getDiscriminant() == 0) cout << "Root is: x = " << user.getRoot1() << endl;
    else cout << "The equation has no real roots" << endl;
    return 0;
}
