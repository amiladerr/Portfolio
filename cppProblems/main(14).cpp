#include <iostream>
#include "StackOfIntegers.h"

using namespace std;
bool isPrime(int n){
    for (int i = 2; i < n; i++)
        if (n % i == 0)return false;
    return true;
}
int main()
{
    StackOfIntegers Stack;
    for (int i = 2; i < 101; i++)
        if (!isPrime(i)) Stack.push(i);

    while (!Stack.isEmpty()) cout << Stack.pop() << " ";
    return 0;
}
