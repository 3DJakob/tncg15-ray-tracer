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
    Point location = Point(5, 0, 4.99);
    Point normal = Point(0,0,-1);
    float numberOfLightPoints = 50;
    float radiance = 0.5;
    vector<Point> lightPoints;

    float sizeX = 2.0;
    float sizeY = 2.0;

    vector<Triangle> triangles;

    AreaLight()
    {
        auto c = location.get();
        // lightPoints(numberOfLightPoints);
        for (int i = 0; i < numberOfLightPoints; i++)
        {
            float rx = (static_cast <float> (rand())) /( static_cast <float> (RAND_MAX)) * sizeX - sizeX / 2;
            float ry = (static_cast <float> (rand())) /( static_cast <float> (RAND_MAX)) * sizeY -sizeY / 2;
            lightPoints.push_back(Point(c.x + rx, c.y + ry, c.z));
        };

        Point p0 = Point(location.get().x - sizeX / 2, location.get().y - sizeY / 2, location.get().z ); // Base
        Point p1 = Point(location.get().x - sizeX / 2, location.get().y + sizeY / 2, location.get().z ); //front
        Point p2 = Point(location.get().x + sizeX / 2, location.get().y - sizeY / 2, location.get().z );  //left
        Point p3 = Point(location.get().x + sizeX / 2, location.get().y + sizeY / 2, location.get().z );  //right

        ColorDbl white = ColorDbl(1.0, 1.0, 1.0);
        triangles.push_back(Triangle(p0, p1, p2, white, 0.0, 1.0));
        triangles.push_back(Triangle(p1, p3, p2, white, 0.0, 1.0));
        
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
