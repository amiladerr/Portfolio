#include <iostream>

using namespace std;

int main() {
  try {
    int x;
    cin >> x;
    if(x == 0) throw "";
    cout << 1. / x;
  }
  catch(...) {
    cout << "Division by 0!";
  }
  return 0;
}
