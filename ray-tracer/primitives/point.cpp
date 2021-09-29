#include <iostream>
#include <string.h>
#include "point.h"
using namespace std;

class Point {
  public:
    double x;
    double y;
    double z;

    Point::Point() = default;

    Point::Point(double _x, double _y, double _z): x(_x), y(_y),z(_z){}

    std::string toString() {
        return "X: " + to_string(x) + "\n Y: " + to_string(y) + "\n Z: " + to_string(z);
    }

    
};
ostream& operator<<(ostream& os, const Point& s)
{
    os << s.x << '/' << s.y << '/' << s.z;
    return os;
}
ostream& operator << (ostream &os, const Point &s) {
    return (os << "X: " << to_string(s.x) << " Y: " << to_string(s.y) << " Z: " << to_string(s.z)  << std::endl);
}
