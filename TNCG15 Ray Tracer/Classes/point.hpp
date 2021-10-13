//
//  point.hpp
//  TNCG15 Ray Tracer
//
//  Created by Alex Knutsson & Jakob Unnebäck on 2021-10-06.
//

#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
#include <string.h>
#include "glm.hpp"


using namespace std;

class Point{
public:
    inline Point(){coordinates=glm::vec3();;}
    Point(double _x, double _y, double _z): coordinates(glm::vec3(_x, _y, _z)) {}
    
    void Normalize(){
        coordinates = glm::normalize(coordinates);
    }
    
    friend ostream& operator<<(ostream &os, const Point &s);
    glm::vec3 get(){
        return coordinates;
    }
    
private:
    glm::vec3 coordinates;
};

ostream& operator<< (ostream &os, const Point &s) {
    return (os << "X: " << to_string(s.coordinates.x) << " Y: " << to_string(s.coordinates.y) << " Z: " << to_string(s.coordinates.z)  << std::endl);
}

#endif // __POINT_H__ 
