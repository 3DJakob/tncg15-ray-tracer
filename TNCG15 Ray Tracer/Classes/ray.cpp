//
//  ray.c
//  TNCG15 Ray Tracer
//
//  Created by Alex Knutsson on 2021-10-06.
//

#include "ray.h"

void Ray::setEnd(Vertex _end){
     endPoint = _end;
}

// Ray::Ray(Point _startPoint, Point direction, Triangle[] triangles) {
//     triangleHit = triangles[0];
//         // Find the first triangle hit
//         // loop through all triangles
        
//         // save start and endpoint and triangle ref
// }

Vertex Ray::getEndPoint() {
    return endPoint;
}

const Vertex &Ray::getStart() const{
    return startPoint;
}