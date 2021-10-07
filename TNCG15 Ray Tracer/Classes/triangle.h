#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include "point.hpp"
#include "glm.hpp"
#include <iostream>

class Triangle
{

public:
    Point p1, p2, p3;
     
//     Triangle();
//     Triangle(Point _p1, Point _p2, Point _p3);
//     ~Triangle();
    
    Triangle (Point p1in, Point p2in, Point p3in) {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
    }

    const Point &getNormal() const;

private:
     glm::vec3 normal;
     
};


#endif // __TRIANGLE_H__
