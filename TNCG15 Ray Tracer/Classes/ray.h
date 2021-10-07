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
    glm::vec3 startPoint;
    glm::vec3 endpoint;
};

#endif /* ray_h */
