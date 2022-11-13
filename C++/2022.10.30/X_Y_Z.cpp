#include <iostream>

using namespace std;

class X;
class Y;
class Z;

class Y
{
public:
    void g(X &x);
};

class Z
{
public:
    void f(X &x);
};

class X
{
public:
    X(int i) : i(i) {}
    friend void Y::g(X &x);
    friend class Z;
    friend void h(X &x);
    void print()
    {
        cout << i;
    }

private:
    int i;
};

void Y::g(X &x)
{
    x.i++;
}

void h(X &x)
{
    x.i +=10;
}

void Z::f(X &x)
{
    x.i += 5;
}

int main()
{
    int a;
    cin >> a;
    X x(a);
    Y y;
    Z z;
    y.g(x);
    z.f(x);
    h(x);
    x.print();
}