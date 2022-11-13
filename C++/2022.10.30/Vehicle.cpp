#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void run1() { cout << "Vehicle run" << endl; }
    virtual void stop() { cout << "vehicle stop" << endl; }
};

class Bicycle : virtual public Vehicle
{
public:
    void run1() { cout << "Bicycle run" << endl; }
    void stop() { cout << "Bicycle stop" << endl; }
};

class Motorcar : virtual public Vehicle
{
public:
    void run1() { cout << "Motorcar run" << endl; }
    void stop() { cout << "Motorcar stop" << endl; }
};

void run(Vehicle v)
{
    v.run1();
}
void run(Bicycle b)
{
    b.run1();
}
void run(Motorcar m)
{
    m.run1();
}

int main(int argc, char const *argv[])
{
    Vehicle veh;
    Bicycle bic;
    Motorcar mot;
    run(veh);
    run(bic);
    run(mot);
    return 0;
}