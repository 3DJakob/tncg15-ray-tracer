#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include "direction.h"
#include "point.h"
#include <iostream>

class Triangle
{

public:
     Triangle(Point _point1, Point _point2, Point _point3){
          point1 = _point1;
          point2 = _point2;
          point3 = _point3;
          edge1 = point1 - point2;
          edge2 = point1 - point2;
          Direction normal.cross(edge1, edge2);
          
          
          
     }
     ~Triangle();
     Point cross(Point _edge1, Point _edge2);
private:
     Direction normal;
     Point point1, point2, point3, edge1, edge2;
};

// Triangle::Triangle(/* args */)
// {
// }

Triangle::Point cross(Point _edge1, Point _edge2){
     Point res;
     return res;
}

Triangle::~Triangle()
{
}

#endif // __TRIANGLE_H__