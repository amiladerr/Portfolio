#include "StopWatch.h"
#include <ctime>

using namespace std;

StopWatch::StopWatch(){
    startTime = time(0);
}
int StopWatch::getStartTime(){
    return startTime;
}
int StopWatch::getEndTime(){
    return endTime;
}
void StopWatch::start(){
    startTime = time(0);
}
void StopWatch::stop(){
    endTime = time(0);
}
int StopWatch::getElapsedTime(){
    return endTime - startTime;
}
