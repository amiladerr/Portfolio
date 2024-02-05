#include <iostream>

using namespace std;

/*

void Swap(int &x, int &y) {
  cout << "Swap (int) called\n";
  int temp = x; x = y; y = temp;
}

double Swap(double &x, double &y) {
  cout << "Swap (double) called\n";
  double temp = x; x = y; y = temp;
}

double Swap(string &x, string &y) {
  cout << "Swap (string) called\n";
  string temp = x; x = y; y = temp;
}

...

It does not lead to anything...

*/

template <typename SomeType>
void Swap(SomeType &x, SomeType &y) {
  SomeType temp = x; x = y; y = temp;
}

template <typename Type1, typename Type2>
void DisplayTwoArguments(Type1 x, Type2 y) {
  cout << x << " " << y << endl;
}

template <typename SomeType>
void DisplayArray(SomeType arr[], int no_of_elements) {
  for(int i = 0; i < no_of_elements; i++) cout << arr[i] << " ";
  cout << endl;
}

template <typename SomeType>
SomeType Multiply(SomeType x, SomeType y) {
  return x * y;
}


int main() {
  int a = 3, b = 5;
  Swap(a, b);                                   // SomeType = int
  DisplayTwoArguments(a, b);                    // Type1 = int, Type2 = int
  double c = 3, d = 5;
  Swap(c, d);                                   // SomeType = double
  DisplayTwoArguments(c, d);                    // Type1 = double, Type2 = double
  string e = "Salih", f = "Delara";
  Swap(e, f);                                   // SomeType = string
  DisplayTwoArguments(e, f);                    // Type1 = string, Type2 = string
  // Swap(a, e);                                // Deduction fails - is Sometype = int or SomeType = string ???
  DisplayTwoArguments(a, e);                    // Type1 = int, Type2 = string
  DisplayTwoArguments(3.5, 4.2);                // Type1 = dozble, Type2 = double
  DisplayTwoArguments<int, double>(3.5, 4.2);   // Type1 = int, Type2 = double (deduction is explicitely turned off here)
  int arr1[5] = {3, 2, 4, 6, 4};
  DisplayArray(arr1, 5);                        // SomeType = int
  string arr2[3] = {"Mehmed", "Ajla", "Tarik"};
  DisplayArray(arr2, 3);                        // SomeType = string
  cout << Multiply(a, b) << endl;               // SomeType = int
  cout << Multiply(e, f) << endl;            // Fails: deduction is ok (SomeType = string), but instantation is not ok
                                                //   because x * y is not valid when x and y are strings
}
