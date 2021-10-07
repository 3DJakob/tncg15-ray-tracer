//
//  direction.hpp
//  TNCG15 Ray Tracer
//
//  Created by Alex Knutsson on 2021-10-06.
//

#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <iostream>
using namespace std;

class Direction {
private:
    double inclination;
    double azimuth;
public:
    inline Direction(){inclination=0.0; azimuth=0.0;}
    Direction(double inInclination, double inAzimuth) : inclination(inInclination), azimuth(inAzimuth){};

    friend ostream& operator<< (ostream &os, const Direction &s);
};

ostream& operator << (ostream &os, const Direction &s) {
    return (os << "Inclination: " << to_string(s.inclination) << " Azimuth: " << to_string(s.azimuth) << std::endl);
}

#endif // __DIRECTION_H__
