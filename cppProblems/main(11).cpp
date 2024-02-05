#include <iostream>
#include "Location.h"

using namespace std;

int main()
{
    Location location;
    double matrix[location.ROW_SIZE][location.COLUMN_SIZE];
    for (int i = 0; i < location.ROW_SIZE; i++)
        for (int j = 0; j < location.COLUMN_SIZE; j++){
                cout << "Enter element (" << i << ", " << j << "): ";
                cin >> matrix[i][j];
        }
    location.locateLargest(matrix);
    cout << "The location of the largest element is " << location.maxValue
        << " at (" << location.row << ", " << location.column << ")" << endl;
    return 0;
}
