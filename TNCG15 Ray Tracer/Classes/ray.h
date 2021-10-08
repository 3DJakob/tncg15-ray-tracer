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
    Triangle triangleHit;
    
    Ray(Point _startPoint, Point direction, Triangle triangles[]) {
        triangleHit = triangles[0];
        startPoint = _startPoint.get();
        // Find the first triangle hit
        // loop through all triangles
        
        double minDist = 9999;
        int matchIndex = -1;
        
//        cout << "START: X " << startPoint.x << " Y " << startPoint.y << " Z " << startPoint.z << endl;
//        cout << "TARGET: " << direction << endl;
//
//        cout << "X: " << (direction.get() - startPoint).x << " Y: " << (direction.get() - startPoint).y << " Z: " << (direction.get() - startPoint).z << endl;
        
        for (int i = 0; i < 20; i++) {
            auto triangle = triangles[i];
            auto res = glm::vec3();
//            cout << direction << endl;
            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
            if (doesHit && res.length() < minDist) {
                cout << "Hit: " << Point(res.x, res.y, res.z) << endl;
                minDist = res.length();
                matchIndex = i;
            }
        }
        
        if (matchIndex != -1) {
            triangleHit = triangles[matchIndex];
        }
        
        
        // save start and endpoint and triangle ref
//        for(Triangle triangle : triangles) {
////            triangle.rayIntersection(ray, minDistance);
//
//        }
    }

    void setEnd(Point _end);
    Point getEndPoint();

    const Point &getStart() const;



private:
    glm::vec3 startPoint;
    glm::vec3 endPoint;
    glm::vec3 dir;
    // Material?
};

#endif /* ray_h */
