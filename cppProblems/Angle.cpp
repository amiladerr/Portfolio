#include <iostream>
#include <cmath>
using namespace std;

const double PI = 4 * atan(1);

class Angle {
     int d, m, s;
    public:
     Angle(int d, int m, int s) { Set(d, m, s); }
     void Set(int d1, int m1, int s1) {
     int tot = 3600 * d1 + 60 * m1 + s1;
     d = (tot / 3600) % 360; m = (tot % 3600) / 60; s = tot % 60;
     }
     Angle() { d = 0; m = 0 ; s = 0; }
     int GetDegrees() const { return d; }
     int GetMinutes() const { return m; } int GetSeconds() const { return s; }
     double GetRadians() const {
     return PI * (3600 * d + 60 * m + s) / 648000;
     }
     friend Angle AddAngles(Angle a1, Angle a2); //{
    // return Angle(a1.d + a2.d, a1.m + a2.m, a1.s + a2.s);
    // }
     static Angle Add(Angle a1, Angle a2) {
     return AddAngles(a1, a2); // Simply call another version...
     }
     void Display() const {
     cout << d << " deg " << m << " min " << s << " sec";
     }
};
Angle AddAngles(Angle a1, Angle a2) {
    return Angle(a1.d + a2.d, a1.m + a2.m, a1.s + a2.s);
}
int main() {
 Angle a1, a2(10, 8, 15), a3(70, 100, 90);
 a1.Display(); cout << endl;
 a2.Display(); cout << endl;
 a3.Display(); cout << endl;
 cout << a3.GetDegrees() << " " << a3.GetMinutes() << " "
 << a3.GetSeconds() << endl << a3.GetRadians() << endl;
 a1 = AddAngles(a2, a3);
 a1.Display(); cout << endl;
 a1 = Angle::Add(a2, a3);
 a1.Display(); cout << endl;
 return 0;
}
