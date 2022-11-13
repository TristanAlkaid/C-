#include <iostream>
#include <math.h>

using namespace std;

double const pi = 3.14;

class Circle
{
protected:
    double radius;

public:
    virtual double getSurfaceArea() = 0;
    virtual double getVolume() = 0;
    virtual void output() = 0;
};

//球
class Sphere : public Circle
{
public:
    Sphere()
    {
        cout << "Input the radius of the sphere:";
        cin >> radius;
    }
    virtual double getSurfaceArea()
    {
        return 4 * pi * radius * radius;
    }
    virtual double getVolume()
    {
        return pi * radius * radius * radius * 4 / 3;
    }
    virtual void output()
    {
        cout << "The area of the sphere:" << getSurfaceArea() << endl;
        cout << "The volume of the sphere:" << getVolume() << endl;
    }
};

//圆柱
class Cylinder : public Circle
{
    double height;

public:
    Cylinder()
    {
        cout << "Input the radius and height of the cylinder:";
        cin >> radius >> height;
    }
    virtual double getSurfaceArea()
    {
        return 2 * pi * radius * radius + 2 * pi * radius * height;
    }
    virtual double getVolume()
    {
        return pi * radius * radius * height;
    }
    virtual void output()
    {
        cout << "The area of the cylinder:" << getSurfaceArea() << endl;
        cout << "The volume of the cylinder:" << getVolume() << endl;
    }
};

//圆锥
class Cone : public Circle
{
    double height;

public:
    Cone()
    {
        cout << "Input the radius and height of the cone:";
        cin >> radius >> height;
    }
    virtual double getSurfaceArea()
    {
        return pi * radius * radius + 2 * pi * radius * sqrt(radius * radius + height * height) / 2;
    }
    virtual double getVolume()
    {
        return pi * radius * radius * height / 3;
    }
    virtual void output()
    {
        cout << "The area of the cone:" << getSurfaceArea() << endl;
        cout << "The volume of the cone:" << getVolume() << endl;
    }
};

int main()
{
    Sphere sphere;
    Cylinder cylinder;
    Cone cone;
    sphere.output();
    cylinder.output();
    cone.output();
}