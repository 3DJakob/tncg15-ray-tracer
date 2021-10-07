//
//  ray.h
//  TNCG15 Ray Tracer
//
//  Created by Alex Knutsson on 2021-10-06.
//

#ifndef ray_h
#define ray_h

#include <stdio.h>
#include "glm.hpp"
#include "triangle.h"
#include "point.hpp"


class Ray {
   
    
public:
//    Triangle triangleHit;
    string foo;
    
    

    // Ray(Point _startPoint, glm::vec3 _dir) : startPoint(_startPoint),  dir(_dir){}
    
    Ray(Point _startPoint, Point direction, Triangle triangles[]) {
//        triangleHit = triangles[0];
//        triangleHit = Triangle(Point(), Point(), Point());
        foo = "test";
        // Find the first triangle hit
        // loop through all triangles
        
        // save start and endpoint and triangle ref
        
//        for(Triangle triangle : triangleList) {
//                triangle.rayIntersection(ray, minDistance);
//            }
    }

    void setEnd(Point _end);
    Point getEndPoint();

    const Point &getStart() const;



private:
    glm::vec3 startPoint;
    glm::vec3 endpoint;
    glm::vec3 dir;
    // Material?
};

#endif /* ray_h */
