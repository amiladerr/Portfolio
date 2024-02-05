#include <iostream>

using namespace std;

int factoriel(int n) {
  cout << "I am just trying to caluclate factoriel of " << n << endl;
  if(n < 0) throw "Factoriel of negative number is not defined!";
  int p = 1;
  for(int i = 1; i <= n; i++) p *= i;
  return p;
}

int main() {
  // Try to see what will happen without try-catch

  try {
    cout << "I am in try block!\n";
    cout << "I am just trying to call factoriel...\n";
    int a = factoriel(1) + factoriel(-3) + factoriel(2);    // -3 is problematic...
    cout << "Call was successful!\n";
    int b = a * 3 + 5;
    int c = b * b - 4;
    cout << "Final result is " << c << endl;
  }
  catch(const char message[]) {          // Parameter message must not be of type string because
    cout << "I am in catch block!\n";    // "..." is not a string, but an array of char!
    cout << message << endl;
  }
}
