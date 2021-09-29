#include <iostream>
#include <string.h>
#include "point.h"
using namespace std;




//Point::~Point() = default;

//Point(double _x, double _y, double _z): x(_x), y(_y),z(_z){}

/* std::string toString(double _x, double _y, double _z) {
    return "X: " + to_string(_x) + "\n Y: " + to_string(_y) + "\n Z: " + to_string(_z);
}  */

/* ostream& operator<<(ostream& os, const Point& s)
{
    os << s.x << '/' << s.y << '/' << s.z;
    return os;
} */
ostream& operator<< (ostream &os, const Point &s) {
    return (os << "X: " << to_string(s.x) << " Y: " << to_string(s.y) << " Z: " << to_string(s.z)  << std::endl);
}
