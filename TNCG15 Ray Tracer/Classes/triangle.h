#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include "point.hpp"
#include "glm.hpp"
#include <iostream>
#include "ColorDbl.h"

class Triangle
{

public:
    Point p1, p2, p3;
    ColorDbl color;
     
    Triangle() {
        p1 = Point();
        p2 = Point();
        p3 = Point();
    };
//     Triangle(Point _p1, Point _p2, Point _p3);
//     ~Triangle();
    Triangle (Point p1in, Point p2in, Point p3in) {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        color = ColorDbl(255.0, 0, 0);
    }
    
    Triangle (Point p1in, Point p2in, Point p3in, ColorDbl colorIn) {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        color = colorIn;
    }
    
//    bool RayIntersectsTriangle(glm::vec3 rayOrigin,
//                               glm::vec3 rayVector,
//                               glm::vec3& outIntersectionPoint);
    
    bool RayIntersectsTriangle(glm::vec3 rayOrigin,
                               glm::vec3 rayVector,
                               glm::vec3& outIntersectionPoint)
    {
        const float EPSILON = 0.0000001;
        glm::vec3 vertex0 = p1.get();
        glm::vec3 vertex1 = p2.get();
        glm::vec3 vertex2 = p3.get();
        glm::vec3 edge1, edge2, h, s, q;
        float a,f,u,v;
        edge1 = vertex1 - vertex0;
        edge2 = vertex2 - vertex0;
        h = glm::cross(rayVector, edge2);
        a = glm::dot(edge1, h);
        if (a > -EPSILON && a < EPSILON)
            return false;    // This ray is parallel to this triangle.
        f = 1.0/a;
        s = rayOrigin - vertex0;
        u = f * glm::dot(s, h);
        if (u < 0.0 || u > 1.0)
            return false;
        q = glm::cross(s, edge1);
        v = f * glm::dot(rayVector, q);
        if (v < 0.0 || u + v > 1.0)
            return false;
        // At this stage we can compute t to find out where the intersection point is on the line.
        float t = f * glm::dot(edge2, q);
        
        if (t > EPSILON) // ray intersection
        {
            outIntersectionPoint = rayOrigin + rayVector * t;
            return true;
        }
        else // This means that there is a line intersection but not a ray intersection.
            return false;
    }

    const Point &getNormal() const;

private:
     glm::vec3 normal;
     
};


#endif // __TRIANGLE_H__
