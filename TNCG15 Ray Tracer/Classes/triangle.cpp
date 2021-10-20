#include <iostream>
#include <string.h>
#include "point.hpp"
using namespace std;
using namespace glm;

//Triangle::Triangle() = default;

//Triangle::Triangle(Point _p1, Point _p2, Point _p3,) : p1(_p1), p2(_p2), p3(_p3) {
//    normal = glm::normalize(glm::cross(p2 - p1, p3 - p1));
//}

//Triangle::~Triangle() = default;

const vec3 &Triangle::getNormal() const {
    vec3 vertex0 = p1.get();
    vec3 vertex1 = p2.get();
    vec3 vertex2 = p3.get();
    vec3 edge1, edge2, res, normal;

    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    res = glm::dot(edge1, edge2);
    normal = gml::normalize(res);
    
    return normal;
}

//bool Triangle::RayIntersectsTriangle(glm::vec3 rayOrigin,
//                           glm::vec3 rayVector,
//                           glm::vec3& outIntersectionPoint)
//{
//    const float EPSILON = 0.0000001;
//    glm::vec3 vertex0 = p1.get();
//    glm::vec3 vertex1 = p2.get();
//    glm::vec3 vertex2 = p3.get();
//    glm::vec3 edge1, edge2, h, s, q;
//    float a,f,u,v;
//    edge1 = vertex1 - vertex0;
//    edge2 = vertex2 - vertex0;
//    h = glm::cross(rayVector, edge2);
//    a = glm::dot(edge1, h);
//    if (a > -EPSILON && a < EPSILON)
//        return false;    // This ray is parallel to this triangle.
//    f = 1.0/a;
//    s = rayOrigin - vertex0;
//    u = f * glm::dot(s, h);
//    if (u < 0.0 || u > 1.0)
//        return false;
//    q = glm::cross(s, edge1);
//    v = f * glm::dot(rayVector, q);
//    if (v < 0.0 || u + v > 1.0)
//        return false;
//    // At this stage we can compute t to find out where the intersection point is on the line.
//    float t = f * glm::dot(edge2, q);
//    
//    if (t > EPSILON) // ray intersection
//    {
//        outIntersectionPoint = rayOrigin + rayVector * t;
//        return true;
//    }
//    else // This means that there is a line intersection but not a ray intersection.
//        return false;
//}

ostream& operator << (ostream &os, const Triangle &t) {
    return (os << "Corner 1: " << t.p1 << "Corner 2: " << t.p2 << "Corner 3: " << t.p3  << std::endl);
}
