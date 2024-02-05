#include "Location.h"

using namespace std;

Location::Location(){
    row = 0;
    column = 0;
}
Location::Location(int newRow, int newColumn, double newMax){
    row = newRow;
    column = newColumn;
    maxValue = newMax;
}
Location Location::locateLargest(const double a[][COLUMN_SIZE]){
    maxValue = a[row][column];
    for (int i = row; i < ROW_SIZE; i++)
        for (int j = column; j < COLUMN_SIZE; j++)
        if (a[i][j] > maxValue){
            maxValue = a[i][j];
            row = i;
            column = j;
        }
    return Location(row, column, maxValue);
}
