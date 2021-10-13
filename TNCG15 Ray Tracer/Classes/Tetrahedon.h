//
//  Tetrahedon.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-12.
//

#ifndef Tetrahedon_h
#define Tetrahedon_h

#include <iostream>
#include <string.h>
#include "triangle.h"
#include "point.hpp"
#include "ColorDbl.h"
#include <vector>
using namespace std;

class Tetrahedon
{

public:
    Point p0;
    Point p1;
    Point p2;
    Point p3;
    double scale = 3;
    int numberOfTriangles = 4;
    vector <Triangle> triangles;
    // vector <Point> tetrahedronPoints;

    ColorDbl red = ColorDbl(255.0, 0.0, 0.0);
    ColorDbl green = ColorDbl(0.0, 255.0, 0.0);
    ColorDbl blue = ColorDbl(0.0, 0.0, 255.0);
    ColorDbl magenta = ColorDbl(255.0, 0.0, 255.0);
    ColorDbl cyan = ColorDbl(0.0, 255.0, 255.0);

    Tetrahedon(Point _p0) {
        //Top
        Point p0 = Point(_p0.get().x, _p0.get().y, -scale+_p0.get().z);
        // Base
        Point p1 = Point(-scale + _p0.get().x, _p0.get().y, scale +_p0.get().z); //front
        Point p2 = Point(_p0.get().x, -scale + _p0.get().y, scale +_p0.get().z);  //left
        Point p3 = Point(_p0.get().x, scale + _p0.get().y, scale +_p0.get().z);  //right

        // tetrahedronPoints.push_back(p0);
        // tetrahedronPoints.push_back(p1);
        // tetrahedronPoints.push_back(p2);
        // tetrahedronPoints.push_back(p3);

        triangles.push_back(Triangle(p0, p3, p1, blue));
        triangles.push_back(Triangle(p0, p1, p2, cyan));
        triangles.push_back(Triangle(p0, p2, p3, red));
        triangles.push_back(Triangle(p1, p2, p3, magenta));

        

    }


    // Triangle triangles[1]
    //     {
    //         // Roof
    //         // Triangle(tetrahedronPoints[0], tetrahedronPoints[2], tetrahedronPoints[1], blue),
    //         // Triangle(tetrahedronPoints[0], tetrahedronPoints[1], tetrahedronPoints[3], magenta),
    //         // Triangle(tetrahedronPoints[0], tetrahedronPoints[3], tetrahedronPoints[2], blue),
    //         // Triangle(tetrahedronPoints[1], tetrahedronPoints[2], tetrahedronPoints[3], magenta),
           
    // };


                             friend ostream &
                             operator<<(ostream &os, const Tetrahedon &s);
    std::string toString(double _x, double _y, double _z);

private:
};

ostream &operator<<(ostream &os, const Tetrahedon &s)
{
    return (os << "Tetrahedon mesh" << std::endl);
}

#endif /* Tetrahedon.h */

