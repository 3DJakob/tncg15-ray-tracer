#include <iostream>
#include <string.h>
#include "point.hpp"
using namespace std;

//Triangle::Triangle() = default;

//Triangle::Triangle(Point _p1, Point _p2, Point _p3,) : p1(_p1), p2(_p2), p3(_p3) {
//    normal = glm::normalize(glm::cross(p2 - p1, p3 - p1));
//}

//Triangle::~Triangle() = default;

const Point &Triangle::getNormal() const {
    return normal;
}

ostream& operator << (ostream &os, const Triangle &t) {
    return (os << "Corner 1: " << t.p1 << "Corner 2: " << t.p2 << "Corner 3: " << t.p3  << std::endl);
}
