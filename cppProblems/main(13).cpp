#include <iostream>
#include "StackOfIntegers.h"

using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    StackOfIntegers Stack;
    for (int i = 1; i < 11; i++)
        Stack.push(num*i);
    while (!Stack.isEmpty()) cout << Stack.pop() << " ";
    return 0;
}
