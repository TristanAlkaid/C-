#include <iostream>

using namespace std;

class car;

class boat
{
private:
    int weight;

public:
    boat(int k) { weight = k; }
    friend int gettotalweight(boat &b, car &c);
};

class car
{
private:
    int weight;

public:
    car(int k) { weight = k; }
    friend int gettotalweight(boat &b, car &c);
};

int gettotalweight(boat &b, car &c)
{
    return b.weight + c.weight;
}

int main()
{
    int boat_w, car_w;
    cout << "Input boat weight:";
    cin >> boat_w;
    cout << "Input car weight:";
    cin >> car_w;
    boat b1(boat_w);
    car c2(car_w);
    cout << "Total weight:" << gettotalweight(b1, c2) << endl;
    return 0;
}