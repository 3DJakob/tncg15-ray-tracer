#ifndef __DIRECTION_H__
#define __DIRECTION_H__


using namespace std;
#include <iostream>
#include "point.h"

class Direction {
private:
    double inclination, azimuth;
    Point startPos, endPos;
public:
    inline Direction(){inclination=0.0; azimuth=0.0;}
    Direction(double inInclination, double inAzimuth) : inclination(inInclination), azimuth(inAzimuth){};

    friend ostream& operator<< (ostream &os, const Direction &s);
};

ostream& operator << (ostream &os, const Direction &s) {
    return (os << "Inclination: " << to_string(s.inclination) << " Azimuth: " << to_string(s.azimuth) << std::endl);
}

#endif // __DIRECTION_H__