#include <iostream>
#include <string.h>
#include "direction.cpp"
using namespace std;

class Vector {
  public:
    Point start;
    Point end;
    Direction direction;

    Vector() {
      
    }

    // std::string toString() {
    //     return "Start: " + to_string(start) + "\n Y: " + to_string(y) + "\n Z: " + to_string(z);
    // }

    
};

ostream& operator << (ostream &os, const Vector &s) {
    return (os << "Start: " << s.start << "End: " << s.end << "Direction: " << s.direction  << std::endl);
}
