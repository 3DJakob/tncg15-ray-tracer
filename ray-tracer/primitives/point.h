#ifndef __POINT_H__
#define __POINT_H__
using namespace std;
class Point
{
private:
    double x,y,z;
public:
    Point();
    // Point(double _x, double _y, double _z);
    friend ostream& operator<<(ostream &os, const Point &s);
    ~Point();
};




Point::Point(/* args */)
{
}

Point::~Point()
{
}

// ostream& operator << (ostream &os, const Point &s);

#endif // __POINT_H__ 