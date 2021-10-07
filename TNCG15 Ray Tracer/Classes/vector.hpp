//
//  vector.hpp
//  TNCG15 Ray Tracer
//
//  Created by Alex Knutsson on 2021-10-06.
//

#ifndef __VECTOR_H__
#define __VECTOR_H__
#include "point.hpp"
#include "direction.hpp"
#include <iostream>

class Vector {
public:
    Vector(Point _start, Point _end, Direction _direction) : start(_start), end(_end), direction(_direction){}

     friend ostream& operator << (ostream &os, const Vector &s);
    // std::string toString() {
    //     return "Start: " + to_string(start) + "\n Y: " + to_string(y) + "\n Z: " + to_string(z);
    // }

private:
     Point start;
     Point end;
     Direction direction;
};

ostream& operator << (ostream &os, const Vector &s) {
    return (os << "Start: " << s.start << "End: " << s.end << "Direction: " << s.direction  << std::endl);
}
#endif // __VECTOR_H__
