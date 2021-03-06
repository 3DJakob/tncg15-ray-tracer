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
    glm::vec3 rayNormal;
    float roughness = 1.0f;
    float emission = 0.0f;

    Triangle()
    {
        p1 = Point();
        p2 = Point();
        p3 = Point();
        rayNormal = getNormal();
        roughness = 1.0f;
    };
    //     Triangle(Point _p1, Point _p2, Point _p3);
    //     ~Triangle();
    Triangle(Point p1in, Point p2in, Point p3in)
    {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        rayNormal = getNormal();
        color = ColorDbl(1.0, 0, 0);
    }

    Triangle(Point p1in, Point p2in, Point p3in, ColorDbl colorIn)
    {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        rayNormal = getNormal();
        color = colorIn;
    }

    Triangle(Point p1in, Point p2in, Point p3in, ColorDbl colorIn, float roughnessIn)
    {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        rayNormal = getNormal();
        color = colorIn;
        roughness = roughnessIn;
    }

    Triangle(Point p1in, Point p2in, Point p3in, ColorDbl colorIn, float roughnessIn, float emissionIn)
    {
        p1 = p1in;
        p2 = p2in;
        p3 = p3in;
        rayNormal = getNormal();
        color = colorIn;
        emission = emissionIn;
    }

    bool RayIntersectsTriangle(glm::vec3 rayOrigin,
                               glm::vec3 rayVector,
                               glm::vec3 &outIntersectionPoint)
    {
        const float EPSILON = 0.0000001;
        glm::vec3 vertex0 = p1.get();
        glm::vec3 vertex1 = p2.get();
        glm::vec3 vertex2 = p3.get();
        glm::vec3 edge1, edge2, h, s, q;
        float a, f, u, v;
        edge1 = vertex1 - vertex0;
        edge2 = vertex2 - vertex0;
        h = glm::cross(rayVector, edge2);
        a = glm::dot(edge1, h);
        if (a > -EPSILON && a < EPSILON)
            return false; // This ray is parallel to this triangle.
        f = 1.0 / a;
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

private:
    //    const glm::vec3 &getNormal() const;
    glm::vec3 &getNormal()
    {
        glm::vec3 vertex0 = p1.get();
        glm::vec3 vertex1 = p2.get();
        glm::vec3 vertex2 = p3.get();
        glm::vec3 edge1, edge2, normal;

        edge1 = vertex1 - vertex0;
        edge2 = vertex2 - vertex0;
        auto res = glm::cross(edge1, edge2);
        normal = glm::normalize(res);

        return normal;
    }
};

bool operator==(Triangle &t1, Triangle &t2)
{
    if (t1.p1 == t2.p1 && t1.p2 == t2.p2 && t1.p3 == t2.p3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(Triangle &t1, Triangle &t2)
{
    return t1 == t2 ? false : true;
}

#endif // __TRIANGLE_H__
