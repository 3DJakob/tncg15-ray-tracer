#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include "point.hpp"
#include "glm.hpp"
#include <iostream>

class Triangle
{

public:
//     Triangle();
     Triangle(Point _p1, Point _p2, Point _p3);
//     ~Triangle();

    const Point &getNormal() const;

private:
     glm::vec3 normal;
     Point p1, p2, p3;
};


#endif // __TRIANGLE_H__
