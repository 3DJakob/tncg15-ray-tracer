//
//  AreaLight.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-12.
//

#ifndef AreaLight_h
#define AreaLight_h

#include <iostream>
#include <string.h>
#include "triangle.h"
#include "point.hpp"
#include "ColorDbl.h"
#include <vector>
using namespace std;

class AreaLight
{

public:
    Point location = Point(-5, 0, 4);
    float numberOfLightPoints = 10;
    float radiance = 1.0;
    vector<Point> lightPoints;

    float sizeX = 1.0;
    float sizeY = 1.0;
    //  ColorDbl green = ColorDbl(0.0, 255.0, 0.0);

    AreaLight()
    {
        auto c = location.get();
        // lightPoints(numberOfLightPoints);
        for (int i = 0; i < numberOfLightPoints; i++)
        {
            float rx = -sizeX/2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(sizeX)));
            float ry = -sizeY/2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(sizeY)));
            lightPoints.push_back(Point(c.x + rx, c.y + ry, c.z));
        };
    }

    friend ostream &
    operator<<(ostream &os, const AreaLight &s);
    std::string toString(double _x, double _y, double _z);

private:
};

ostream &operator<<(ostream &os, const AreaLight &s)
{
    return (os << "Area light" << std::endl);
}

#endif /* AreaLight_h */
