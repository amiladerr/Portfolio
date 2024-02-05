#include <iostream>

// This version implements operators as member functions!
// The drawback is that the first operand of all operators must be strictly of type Complex!
// (no conversions are allowed)

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
  Complex operator+(Complex z2);
  Complex operator-(Complex z2);
  Complex operator*(Complex z2);
  Complex operator/(Complex z2);
  Complex &operator+=(Complex z2);
  Complex &operator-=(Complex z2);
  Complex &operator*=(Complex z2);
  Complex &operator/=(Complex z2);
  Complex operator-();                                   // Unary "-"
  bool operator==(Complex z2);
  bool operator!=(Complex z2);
  friend ostream &operator<<(ostream &mystream, Complex z);   // opetator<< must be non-member, necause the first operand
};                                                            //   is not of type Complex


Complex Complex::operator+(Complex z2) {
  return Complex(re + z2.re, im + z2.im);
}

Complex Complex::operator-(Complex z2) {
  return Complex(re - z2.re, im - z2.im);
}

Complex Complex::operator*(Complex z2) {
  return Complex(re * z2.re - im * z2.im, re * z2.im + im * z2.re);
}

Complex Complex::operator/(Complex z2) {
  double temp = z2.re * z2.re + z2.im * z2.im;
  return Complex((re * z2.re + im * z2.im) / temp, (im * z2.re - re * z2.im) / temp);
}

// Next few functions returns a reference. This will avoid making a copy of the result.
// But, you must be sure that returned object will be alive after the function is finished
// (i.e. it must not be a local variable or non-reference parameter)

Complex &Complex::operator+=(Complex z2) {
  re += z2.re; im += z2.im;
  return *this;                                 // Returns the object on which the function is called...
}

Complex &Complex::operator-=(Complex z2) {
  re -= z2.re; im -= z2.im;
  return *this;
}

Complex &Complex::operator*=(Complex z2) {
  double old_re = re;                             // Temporary is necessary!!!
  re = re * z2.re - im * z2.im;
  im = old_re * z2.im + im * z2.re;
  return *this;
}

/*

Simpler, but less efficient is:

Complex &Complex::operator*=(Complex z2) {
  *this = *this * z2;
  return *this;
}

or even shorter:

Complex &Complex::operator*=(Complex z2) {
  return *this = *this * z2;
}

*/

Complex Complex::operator-() {
  return Complex(-re, -im);
}

Complex &Complex::operator/=(Complex z2) {
  return *this = *this / z2;                              // Shortcut for *this = *this / z2; return *this;
}

bool Complex::operator==(Complex z2) {
  return re == z2.re && im == z2.im;
}

bool Complex::operator!=(Complex z2) {
  return re != z2.re || im != z2.im;
}

// operator<< is the same as in previous version

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
  // q = 3 * p;                 // But, this will not compile!!!
  cout << q << endl;
  Complex r(2, 2);
  cout << p * q - r << endl;
  if(p == q) cout << "equal";
  else cout << "not equal";
}

