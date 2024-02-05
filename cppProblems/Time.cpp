#include "Time.h"
#include <ctime>

using namespace std;

Time::Time(){
    int totalSeconds = time(0);
    second = totalSeconds % 60;
    int totalMinutes = totalSeconds / 60;
    minute = totalMinutes % 60;
    int totalHours = totalMinutes / 60;
    hour = totalHours % 24;
}
Time::Time(int elapseTime){
    second = elapseTime % 60;
    int totalMinutes = elapseTime / 60;
    minute = totalMinutes % 60;
    int totalHours = totalMinutes / 60;
    hour = totalHours % 24;
}
Time::Time(int newHour, int newMinute, int newSecond){
    hour = newHour;
    minute = newMinute;
    second = newSecond;
}
int Time::getHour(){
    return hour;
}
int Time::getMinute(){
    return minute;
}
int Time::getSecond(){
    return second;
}
void Time::setTime(int elapseTime){
    int elapseSecond = elapseTime % 60 - second;
    int totalMinutes = elapseTime / 60;
    int elapseMinute = totalMinutes % 60 - minute;
    int totalHours = totalMinutes / 60;
    int elapseHour = totalHours % 24 - hour;
    second += elapseSecond;
    while (second >= 60){
        minute++;
        second /= 60;
    }
    minute += elapseMinute;
    while (minute >= 60){
        hour++;
        minute /= 60;
    }
    hour += elapseHour;
    while (hour > 24) hour /= 24;
}

