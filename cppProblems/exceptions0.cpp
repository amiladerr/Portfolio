#include <iostream>

using namespace std;

int factoriel(int n) {
  if(n < 0) throw n;
  int p = 1;
  for(int i = 1; i <= n; i++) p *= i;
  return p;
}

int main() {
  try {
    int n;
    cin >> n;
    cout << factoriel(n) << endl;
    cout << "Everything was fine!\n";
  }
  catch(int arg) {
    cout << "Something were wrong!\n";
    cout << "Problematic argument: " << arg << endl;
  }
  cout << "Goodbye!";
}
