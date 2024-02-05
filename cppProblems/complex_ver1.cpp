#include <iostream>

using namespace std;

class Complex {
  double re, im;              // re = real part, im = imaginary part
public:
  void Set(double re1, double im1) { re = re1; im = im1; }
  Complex(double re, double im) { Set(re, im); }
  Complex() { Set(0, 0); }
  Complex(double x) { Set(x, 0); }                       // Necessary, to support conversion double => Complex
  double GetReal() const { return re; }
  double GetImag() const { return im; }
  friend Complex operator+(Complex z1, Complex z2);
  friend Complex operator-(Complex z1, Complex z2);
  friend Complex operator*(Complex z1, Complex z2);
  friend Complex operator/(Complex z1, Complex z2);
  friend Complex &operator+=(Complex &z1, Complex z2);
  friend Complex &operator-=(Complex &z1, Complex z2);
  friend Complex &operator*=(Complex &z1, Complex z2);
  friend Complex &operator/=(Complex &z1, Complex z2);
  friend Complex operator-(Complex z);                   // Unary "-"
  friend bool operator==(Complex z1, Complex z2);
  friend bool operator!=(Complex z1, Complex z2);
  friend ostream &operator<<(ostream &mystream, Complex z);
};

/*

// This version does not require friendship...
Complex operator+(Complex z1, Complex z2) {
  return Complex(z1.GetReal() + z2.GetReal(), z1.GetImag() + z2.GetImag());
}

*/

// This version requires friendship (re and im are private=!!!
Complex operator+(Complex z1, Complex z2) {
  return Complex(z1.re + z2.re, z1.im + z2.im);
}

Complex operator-(Complex z1, Complex z2) {
  return Complex(z1.re - z2.re, z1.im - z2.im);
}

Complex operator*(Complex z1, Complex z2) {
  return Complex(z1.re * z2.re - z1.im * z2.im, z1.re * z2.im + z1.im * z2.re);
}

Complex operator/(Complex z1, Complex z2) {
  double temp = z2.re * z2.re + z2.im * z2.im;
  return Complex((z1.re * z2.re + z1.im * z2.im) / temp,
    (z1.im * z2.re - z1.re * z2.im) / temp);
}

// Next few functions returns a reference. This will avoid making a copy of the result.
// But, you must be sure that returned object will be alive after the function is finished
// (i.e. it must not be a local variable or non-reference parameter)

Complex &operator+=(Complex &z1, Complex z2) {
  z1.re += z2.re; z1.im += z2.im;                      // More efficient than z1 = z1 + z2:
  return z1;
}

Complex &operator-=(Complex &z1, Complex z2) {
  z1.re -= z2.re; z1.im -= z2.im;
  return z1;
}

Complex &operator*=(Complex &z1, Complex z2) {
  double temp = z1.re;                             // Temporary is necessary!!!
  z1.re = z1.re * z2.re - z1.im * z2.im;
  z1.im = temp * z2.im + z1.im * z2.re;
  return z1;
}

Complex operator-(Complex z) {
  return Complex(-z.re, -z.im);
}

/*

Simpler, but less efficient is:

Complex &operator*=(Complex &z1, Complex z2) {
  z1 = z1 * z2;
  return z1;
}

or even shorter:

Complex &operator*=(Complex &z1, Complex z2) {
  return z1 = z1 * z2;
}

*/

Complex &operator/=(Complex &z1, Complex z2) {
  return z1 = z1 / z2;                              // Shortcut for z1 = z1 / z2; return z1;
}

bool operator==(Complex z1, Complex z2) {
  return z1.re == z2.re && z1.im == z2.im;
}

bool operator!=(Complex z1, Complex z2) {
  return z1.re != z2.re || z1.im != z2.im;
}

// To implement operator<< for some class (say MyClass):
//   1. return type of operator<< must be reference to ostream
//   2. first argument must be reference to ostream too
//   3. name of the first argument is not important (say mysttream)
//   4. typo of second argument must be MyClass (name is not important)
//   5. do everthing like in Display function but:
//        5.1 use name of the first argument (i.e. mystream) instead of cout
//        5.2 access atributes using name of the second argument instead of direct access
//   6. at the end, return the first argument (i.e. mystream)

ostream &operator<<(ostream &mystream, Complex z) {
  if(z.re != 0 || z.re == 0 && z.im == 0) mystream << z.re;    // don't display zero real part except if complete number is 0
  if(z.im > 0) {
    if(z.re != 0) mystream << "+";     // do not write + before imaginary part if real part was 0
    if(z.im != 1) mystream << z.im;     // do not write imaginary part before i if it is equal to 1
    mystream << "i";
  }
  else if(z.im < 0) {
    mystream << "-";
    if(z.im != -1) mystream << -z.im;
    mystream << "i";
  }
  return mystream;
}

int main() {
  Complex p(2, 3);
  Complex q(4, 1);
  cout << p << endl;
  q = p * 3;                    // This will automatically be interpreted as q = p * Complex(3);
  cout << q << endl;
  Complex r(2, 2);
  cout << p * q - r << endl;
  if(p == q) cout << "equal";
  else cout << "not equal";
}

