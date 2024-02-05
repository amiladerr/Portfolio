#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time time1;
    Time time2(555550);
    cout << "Time 1: " << time1.getHour() << ":" << time1.getMinute() << ":" << time1.getSecond() << " GMT" << endl
         << "Time 2: " << time2.getHour() << ":" << time2.getMinute() << ":" << time2.getSecond() << " GMT" << endl;
    return 0;
}
