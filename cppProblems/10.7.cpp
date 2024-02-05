#include <iostream>
#include <string>

using namespace std;

void countDigits (const int& number, int dArray[], int n){
    for (int i = 0; i < n; i++) dArray[i] = 0;
    int num = number;
    int arr[10000], Size = 0;
    while (num > 0){
        arr[Size] = num%10;
        Size++;
        num /= 10;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < Size; j++)
            if (arr[j] == i) dArray[i]++;
       if (dArray[i] > 0) cout << i << ": " << dArray[i] << " times" << endl;
    }
}
int main(){
    int n, dArr[10];
    cout << "Enter a number: ";
    cin >> n;
    countDigits(n, dArr, 10);
    return 0;
}
