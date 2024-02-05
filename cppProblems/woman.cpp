#include <iostream>

using namespace std;

struct Woman {
private:
  int age;
public:
  void SetAge(int age1) { age = age1; }
  int GetAge() { return age - 10; }
};

int main() {
  Woman w;
  w.SetAge(35);
  cout << "My age is " << w.GetAge() << endl;
}
