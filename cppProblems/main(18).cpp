#include <iostream>
#include "MyInteger.h"
#include <string>

using namespace std;

int main()
{
    MyInteger num(3);
    cout << "Value: " << num.getValue() << endl
         << "Is even? " << num.isEven() << endl
         << "Is odd? " << num.isOdd() << endl
         << "Is prime? " << num.isPrime() << endl
         << "ParseInt: " << num.parseInt("123") << endl;
    MyInteger num2(15);
    cout << "Is even? " << num2.isEven(15) << endl
         << "Is odd? " << num2.isOdd(15) << endl
         << "Is prime? " << num2.isPrime(15) << endl
         << "ParseInt: " << num2.parseInt("123") << endl;
    MyInteger num3(5);
    cout << "Is even? " << num3.isEven(num3) << endl
         << "Is odd? " << num3.isOdd(num3) << endl
         << "Is prime? " << num3.isPrime(num3) << endl;
    cout << "Equal? " << num.equals(15) << endl
         << "Equal? " << num2.equals(num3) << endl;
    return 0;
}
