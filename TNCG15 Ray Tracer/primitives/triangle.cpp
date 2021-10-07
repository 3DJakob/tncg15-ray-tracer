#include <iostream>
#include <string.h>
#include "point.h"
using namespace std;

class Triangle {
  public:
    Point corner1;
    Point corner2;
    Point corner3;


    Triangle() {
      
    }

    // std::string toString() {
    //     return "Start: " + to_string(start) + "\n Y: " + to_string(y) + "\n Z: " + to_string(z);
    // }

    
};

ostream& operator << (ostream &os, const Triangle &s) {
    return (os << "Corner 1: " << s.corner1 << "Corner 2: " << s.corner2 << "Corner 3: " << s.corner3  << std::endl);
}
