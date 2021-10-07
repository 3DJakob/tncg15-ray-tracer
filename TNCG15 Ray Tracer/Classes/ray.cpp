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

Vertex Ray::getEndPoint() {
    return endPoint;
}

const Vertex &Ray::getStart() const{
    return startPoint;
}