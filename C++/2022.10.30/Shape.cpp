#include <iostream>

#define Pi 3.14

using namespace std;

class Shape
{
public:
    virtual void output() = 0;
    virtual ~Shape(){};
};

class Rectangle : public Shape
{
private:
    int lenth, width;

public:
    Rectangle()
    {
        cout << "Input a,b:";
        cin >> lenth >> width;
    }
    virtual void output()
    {
        cout << "Rectangle Area:" << lenth * width;
    }
};

class Circle : public Shape
{
private:
    int r;

public:
    Circle()
    {
        cout << "Input r:";
        cin >> r;
    }
    virtual void output()
    {
        cout << "Circle Area:" << Pi * r * r;
    }
};

// class Square : public Rectangle
// {
// private:
//     int a;

// public:
//     Square()
//     {
//         cout << "Input a:";
//         cin >> a;
//     }
//     virtual void output()
//     {
//         cout << "Square Area:" << a * a;
//     }
// };

int main()
{
    Rectangle R;
    Circle C;
    R.output();
    // cout << "," ;
    C.output();
}