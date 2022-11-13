#include <iostream>

using namespace std;

// Point
class Point
{
    private:
    int x; //坐标x
    int y; //坐标y

public:
    //无参构造
    Point() {}
    //有参构造
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    ~Point() {} //析构函数

    friend const Point operator+(const Point &pt1, const Point &pt2);
	friend const Point operator-(const Point &pt1, const Point &pt2);
    Point operator+=(const Point &pt);
	friend bool operator==(const Point &pt1, const Point &pt2);
	friend ostream &operator<<(ostream &out, const Point &pt);
};

//实现+重载
const Point operator+(const Point &pt1, const Point &pt2)
{
    Point P;
    P.x = pt1.x + pt2.x;
    P.y = pt1.y + pt2.y;
    return P;
}

//实现-重载
const Point operator-(const Point &pt1, const Point &pt2)
{
    Point P;
    P.x = pt1.x - pt2.x;
    P.y =  pt1.y - pt2.y;
    return P;
}

Point Point::operator+=(const Point &pt)
{
    this->x += pt.x;
    this->y += pt.y;
    return *this;
}

bool operator==(const Point &pt1, const Point &pt2)
{
    return (pt1.x == pt2.x) && (pt1.y == pt2.y);
}

//<<重载
ostream &operator<<(ostream &out, const Point &p)
{
    out << p.x << "," << p.y ;
    return out;
}

int main(int argc, char const *argv[])
{
    Point p1(2,3);
    cout<<p1<<endl;
    Point p2(4,5);
    cout<<p2<<endl;
    Point p3 = p1+p2;    
    cout<<p3<<endl;
    p3 = p2-p1;
    cout<<p3<<endl;
    p1 += p2;
    cout<<p1<<endl;
    cout<<(p1==p2)<<endl;
    return 0;
}

