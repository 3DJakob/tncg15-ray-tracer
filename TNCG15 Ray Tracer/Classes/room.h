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

class Room
{

public:
    // inline Mesh(){x=0.0; y=0.0; z=0.0;}
    Room() {

    }

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
    
    ColorDbl green = ColorDbl(0.0, 255.0, 0.0);

    Triangle triangles[20]
        {
            // Roof
            Triangle(points[0], points[1], points[5]),
            Triangle(points[1], points[2], points[5]),
            Triangle(points[2], points[4], points[5]),
            Triangle(points[2], points[3], points[4]),

            // Sides
            Triangle(points[0], points[11], points[6], green),
            Triangle(points[0], points[5], points[11], green),
            Triangle(points[5], points[10], points[11], green),
            Triangle(points[5], points[4], points[10], green),

            Triangle(points[4], points[9], points[10], green),
            Triangle(points[3], points[9], points[4], green),
            Triangle(points[3], points[8], points[9], green),
            Triangle(points[2], points[8], points[3], green),

            Triangle(points[2], points[7], points[8], green),
            Triangle(points[1], points[7], points[2], green),
            Triangle(points[0], points[6], points[1], green),
            Triangle(points[1], points[6], points[7], green),

            // Floor
            Triangle(points[6], points[11], points[7]),
            Triangle(points[7], points[11], points[8]),
            Triangle(points[8], points[11], points[10]),
            Triangle(points[8], points[10], points[9]),
    };


                             friend ostream &
                             operator<<(ostream &os, const Room &s);
    std::string toString(double _x, double _y, double _z);

private:
};

ostream &operator<<(ostream &os, const Room &s)
{
    return (os << "Room mesh" << std::endl);
}

#endif /* room_h */
