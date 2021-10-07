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


class Ray {
   
    
public:
    Ray(Point _startPoint, glm::vec3 _dir) : startPoint(_startPoint),  dir(_dir){}

    void setEnd(Vertex _end);
    Vertex getEndPoint();

    const Vertex &getStart() const;



private:
    glm::vec3 startPoint;
    glm::vec3 endpoint;
    glm::vec3 dir;
    // Material?
};

#endif /* ray_h */
