#include <iostream>

using namespace std;

int factoriel(int n) {
  cout << "I am just trying to caluclate factoriel of " << n << endl;
  if(n < 0) throw n;
  int p = 1;
  for(int i = 1; i <= n; i++) p *= i;
  return p;
}

int f(int n) {
  cout << "Calling factoriel...\n";
  int x = factoriel(n);
  cout << "Call of factoriel was successful!\n";
  return x;
}
int g(int n) {
  cout << "Calling f...\n";
  int x = f(n);
  cout << "Call of f was successful!\n";
  return x;
}

int h(int n) {
  cout << "Calling g...\n";
  int x;
  x = g(n);
  cout << "Call of g was successful!\n";
  return x;
}

int main() {
  try {
    cout << "I am just trying to call h...\n";
    int a = h(-3);                                   // Try to change 3 into -3 to see what happens...
    cout << "Call of h was successful!\n";
    cout << "Result is " << a << endl;
  }
  catch(int e) {
    cout << "I am in catch inside main...\n";
    cout << "Problematic argument was " << e << endl;
  }
}
