#include <iostream>
#include <stdexcept>

using namespace std;

class A {
protected:
    int a, b;
public:
    A() : a(3), b(0) { cout << "A1: " << a << " " << b << endl; }
    A(int a, int b) : a(a), b(b) { cout << "A2: " << a << " " << b << endl; }
    ~A() { cout << "A3: " << a << " " << b << endl; }
    void p() { cout << "pA: " << a << " " << b << endl; }
    virtual void g() { cout << "gA: " << a << " " << b << endl; }
};

class B : public A {
    int c;
public:
    B() : A(1, 5) { cout << "B1: " << a << " " << b << " " << c << endl; }
    B(int a) : c(a) { cout << "B2: " << a << " " << b << " " << c << endl; }
    ~B() { cout << "B3: " << a << b << endl; }
    void p() { A::p(); cout << "pB: " << a << " " << b << " " << c << endl; }
    void g() { cout << "gB: " << a << " " << b << " " << c << endl; }
};

void p(A a) { a.p(); a.g(); }
void g(A &a) { a.p(); a.g(); }

int main(){

    A a; B b(2);
    a.p(); a.g(); b.p(); b.g();
    A *r = new A(7, 4), *s = new B;
    B *t = new B(6);
    r->p(); s->p(); t->p();
    r->g(); s->g(); t->g();
    p(a); p(b); g(a); g(b);
    return 0;
}
