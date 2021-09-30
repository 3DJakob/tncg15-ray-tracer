#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
#include <string.h>
using namespace std;

class Point{ 
public:
    inline Point(){x=0.0; y=0.0; z=0.0;}
    Point(double _x, double _y, double _z);
    
    //~Point();
    friend ostream& operator<<(ostream &os, const Point &s);
    std::string toString(double _x, double _y, double _z);
private:
    double x;
    double y;
    double z;
};

ostream& operator<< (ostream &os, const Point &s) {
    return (os << "X: " << to_string(s.x) << " Y: " << to_string(s.y) << " Z: " << to_string(s.z)  << std::endl);
}

#endif // __POINT_H__ 