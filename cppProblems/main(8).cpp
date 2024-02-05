#include <iostream>
#include "EvenNumber.h"

using namespace std;

int main()
{
    EvenNumber evenNumber(16);
    cout << evenNumber.getPrevious() << " " << evenNumber.getValue() << " " << evenNumber.getNext() << endl;
    return 0;
}
