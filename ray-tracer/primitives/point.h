#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
#include <string.h>
using namespace std;

class Point{ 
public:
    inline Point(){x=0.0; y=0.0; z=0.0;}
    ~Point() = default;
    Point(double _x, double _y, double _z): x(_x), y(_y),z(_z){}
    Point& operator-(const Point& inPoint);
    friend ostream& operator<<(ostream &os, const Point &s);
    std::string toString(double _x, double _y, double _z);
private:
    double x, y, z;
    // glm::vec3 position;
};
Point& Point::operator-(const Point& inPoint) {
    Point res;
    res.x = this->x - inPoint.x;
    res.y = this->y - inPoint.y;
    res.z = this->z - inPoint.z;
    return res;
}


ostream& operator<< (ostream &os, const Point &s) {
    return (os << "X: " << to_string(s.x) << " Y: " << to_string(s.y) << " Z: " << to_string(s.z)  << std::endl);
}

#endif // __POINT_H__ 