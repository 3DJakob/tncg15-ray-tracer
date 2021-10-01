#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
#include <string.h>
#include "triangle.h"
#include "point.h"
using namespace std;

class Mesh
{

public:
    // inline Mesh(){x=0.0; y=0.0; z=0.0;}
    Mesh(string type)
    {
        if (type == "room")
        {
            Point Points[12]
            {
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
            }




        } else (type == "box") {
            // Box mesh code
        }


    }

    friend ostream &operator<<(ostream &os, const Mesh &s);
    std::string toString(double _x, double _y, double _z);

private:
    double x, y, z;
    // glm::vec3 position;
};

ostream &operator<<(ostream &os, const Mesh &s)
{
    return (os << "Room mesh" << std::endl);
}

#endif // __POINT_H__