#include <iostream>
#include <iomanip>

using namespace std;
const int N = 3;

void addMatrix (const double a[][N], const double b[][N], double c[][N]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < N; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
int main(){
    double arr1[3][N], arr2[3][N], arr3[3][N];
    cout << "Enter matrix1: ";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            cin >> arr1[i][j];
    cout << "Enter matrix2: ";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            cin >> arr2[i][j];
    cout << "The addition of the matrices is: " << endl;

    addMatrix(arr1, arr2, arr3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < N; j++){ cout << setw(4) << left << arr1[i][j];}
        if (i == 1) cout << "+";
        else cout << " ";
        for (int k = 0; k < N; k++) {cout << setw(4) << left << arr2[i][k];}
        if (i == 1) cout << "=";
        else cout << " ";
        for (int l = 0; l < N; l++) {cout << setw(4) << left << arr3[i][l];}
        cout << endl;
        }
    return 0;
}
