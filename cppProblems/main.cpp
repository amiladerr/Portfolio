#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date date1;
    Date date2(561555550);
    cout << "Date 1: \nYear: " << date1.getYear() << " Month: " << date1.getMonth() << " Day: " << date1.getDay() << endl;
    cout << "Date 2: \nYear: " << date2.getYear() << " Month: " << date2.getMonth() << " Day: " << date2.getDay() << endl;
    return 0;
}
