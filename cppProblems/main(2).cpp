#include <iostream>
#include "StopWatch.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        int where_is_min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] > a[where_is_min]){
                where_is_min = j;
                swap(a[i], a[where_is_min]);
        }
    }
}
int main()
{
    int arr[100000];
    srand(time(0));
    for (int i = 0; i < 100000; i++) arr[i] = rand();
    StopWatch startTiming;
    startTiming.start();
    selectionSort(arr, 100000);
    startTiming.stop();
    cout << "Time it takes to sort 100000 element using selection sort: " << startTiming.getElapsedTime() << endl;
    return 0;
}
