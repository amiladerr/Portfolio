#include <iostream>
#include <string>
#include <stdexcept>        // standard exception objects...

using namespace std;

int main() {
  try {
    string s = "Computer science";
    cout << s.at(10) << endl;           // Try to put 100 instead of 10
  }
  catch(out_of_range exc) {
    cout << "I am in catch block for out of range errors!\n";
    cout << "Explanation message: " << exc.what() << endl;
  }
  cout << "Goodbye!\n";
}
