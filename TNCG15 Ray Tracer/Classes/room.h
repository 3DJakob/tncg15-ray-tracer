//
//  room.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-07.
//

#ifndef room_h
#define room_h

#include <iostream>
#include <string.h>
#include "triangle.h"
#include "point.hpp"
#include "ColorDbl.h"
using namespace std;
#include <vector>

class Room
{

public:
    // inline Mesh(){x=0.0; y=0.0; z=0.0;}
    vector <Triangle> triangles;
    
    
    Point points[12]{
        Point(-3.0, 0.0, 5.0),  //p0Roof
        Point(0.0, 6.0, 5.0),   //p1Roof
        Point(10.0, 6.0, 5.0),  //p2Roof
        Point(13.0, 0.0, 5.0),  //p3Roof
        Point(10.0, -6.0, 5.0), //p4Roof
        Point(0.0, -6.0, 5.0),  //p5Roof

        Point(-3.0, 0.0, -5.0),  //p6Floor
        Point(0.0, 6.0, -5.0),   //p7Floor
        Point(10.0, 6.0, -5.0),  //p8Floor
        Point(13.0, 0.0, -5.0),  //p9FLoor
        Point(10.0, -6.0, -5.0), //p10Floor
        Point(0.0, -6.0, -5.0),  //p11Floor
    };

    Room() {
        // Roof
        triangles.push_back(Triangle(points[0], points[1], points[5], white));
        triangles.push_back(Triangle(points[1], points[2], points[5], white));
        triangles.push_back(Triangle(points[2], points[4], points[5], white));
        triangles.push_back(Triangle(points[2], points[3], points[4], white));

        // Sides
        triangles.push_back(Triangle(points[0], points[11], points[6],  white));
        triangles.push_back(Triangle(points[0], points[5], points[11],  white));
        triangles.push_back(Triangle(points[5], points[10], points[11], blue));
        triangles.push_back(Triangle(points[5], points[4], points[10],  blue));
        
        triangles.push_back(Triangle(points[4], points[9], points[10], orange));
        triangles.push_back(Triangle(points[3], points[9], points[4], orange));
        triangles.push_back(Triangle(points[3], points[8], points[9] ));
        triangles.push_back(Triangle(points[2], points[8], points[3] ));

        triangles.push_back(Triangle(points[2], points[7], points[8], cyan));
        triangles.push_back(Triangle(points[1], points[7], points[2], cyan));
        triangles.push_back(Triangle(points[0], points[6], points[1], red));
        triangles.push_back(Triangle(points[1], points[6], points[7], red));

        // Floor
        triangles.push_back(Triangle(points[6], points[11], points[7], white));
        triangles.push_back(Triangle(points[7], points[11], points[8], white));
        triangles.push_back(Triangle(points[8], points[11], points[10],white));
        triangles.push_back(Triangle(points[8], points[10], points[9], white));
    }


    friend ostream &operator<<(ostream &os, const Room &s);
    std::string toString(double _x, double _y, double _z);

private:
    ColorDbl red = ColorDbl(255.0, 0.0, 0.0);
    ColorDbl green = ColorDbl(0.0, 255.0, 0.0);
    ColorDbl blue = ColorDbl(0.0, 0.0, 255.0);
    ColorDbl orange = ColorDbl(255.0, 120.0, 0.0);
    ColorDbl gray = ColorDbl(150.0, 150.0, 150.0);
    ColorDbl cyan = ColorDbl(0.0, 255.0, 255.0);
    ColorDbl lightGray = ColorDbl(244.0, 244.0, 244.0);
    ColorDbl white = ColorDbl(255.0, 255.0, 255.0);
};

ostream &operator<<(ostream &os, const Room &s)
{
    return (os << "Room mesh" << std::endl);
}

#endif /* room_h */
