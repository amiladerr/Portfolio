#include <iostream>
#include <stdexcept>        // standard exception objects...

using namespace std;

int factoriel(int n) {
  cout << "I am just trying to caluclate factoriel of " << n << endl;
  if(n < 0) throw domain_error("Factoriel of negative number is not defined!");
  else {
    int p = 1;
    for(int i = 1; i <= n; i++) p *= i;
    return p;
  }
}

int main() {
  try {
    cout << "I am in try block!\n";
    cout << "I am just trying to call factoriel...\n";
    int a = factoriel(1) + factoriel(-3) + factoriel(2);
    cout << "Call was successful!\n";
    int b = a * 3 + 5;
    int c = b * b - 4;
    cout << "Final result is " << c << endl;
  }
  catch(range_error exc) {
    cout << "I am in catch block for range errors!\n";
    cout << exc.what();
  }
//  catch(domain_error exc) {                                      // Try to comment out this, then also the following catch block
//    cout << "I am in catch block for domain errors!\n";          // to see what happens...
//    cout << exc.what();
//  }
//  catch(...) {
//    cout << "I am in catch block for unspecified errors!\n";
//  }
}
