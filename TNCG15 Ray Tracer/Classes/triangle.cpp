#include <iostream>
#include <string.h>
#include "point.hpp"
using namespace std;

//Triangle::Triangle() = default;

Triangle::Triangle(Point _p0, Point _p1, Point _vp,) : p0(_p0), p1(_p1), p2(_p2) {
    normal = glm::normalize(glm::cross(p1 - p0, p2 - p0));
}

//Triangle::~Triangle() = default;

const Point &Triangle::getNormal() const {
    return normal;
}

ostream& operator << (ostream &os, const Triangle &t) {
    return (os << "Corner 1: " << t.p1 << "Corner 2: " << t.p2 << "Corner 3: " << t.p3  << std::endl);
}
