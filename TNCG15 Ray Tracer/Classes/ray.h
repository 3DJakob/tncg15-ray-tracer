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
#include "AreaLight.h"


class Ray {
   
    
public:
    Triangle triangleHit;
    Point rayPoint;
    
    
    Ray(Point _startPoint, Point direction, vector<Triangle> triangles, AreaLight sceneAreaLight) {
        triangleHit = triangles[0];
        startPoint = _startPoint.get();
        
        
        double minDist = 9999;
        glm::vec3 hitLocation;
        
        for (Triangle triangle : triangles) {
            auto res = glm::vec3();
//            cout << direction << endl;
            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
            if (doesHit && res.length() < minDist) {
//                cout << "Hit: " << Point(res.x, res.y, res.z) << endl;
                minDist = res.length();
                triangleHit = triangle;
                hitLocation = res;
            }
        }
        rayPoint = Point(hitLocation.x, hitLocation.y, hitLocation.z);
        
        // Calculate number of seen pointlights
//        for(Point light : sceneAreaLight.lightPoints) {
//            // Check if seen!
//            for (Triangle triangle : triangles) {
//
//            }
////            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
//        }
        
        
        
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
