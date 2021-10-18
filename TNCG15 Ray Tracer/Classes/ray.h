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
    double directLight;
    
    
    Ray(Point _startPoint, Point direction, vector<Triangle> triangles, AreaLight sceneAreaLight) {
        triangleHit = triangles[0];
        startPoint = _startPoint.get();
        
        
        double minDist = 9999;
        glm::vec3 hitLocation;
        
        for (Triangle triangle : triangles) {
            auto res = glm::vec3();
//            cout << direction << endl;
            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
            if (doesHit && (res.length() < minDist)) {
//                cout << "Hit: " << Point(res.x, res.y, res.z) << endl;
                minDist = res.length();
                triangleHit = triangle;
                hitLocation = res;
            }
        }
        rayPoint = Point(hitLocation.x, hitLocation.y, hitLocation.z);
        
        directLight = 0.0;
        
        // Calculate number of seen pointlights
        for(Point light : sceneAreaLight.lightPoints) {
            // Check if seen!
//            auto objectTriangles = triangles. // No need to check for intersect with walls here...
            std::vector<Triangle> objectTriangles(triangles.begin(), triangles.end() - 20);
            bool doesHit = false;
            for (Triangle triangle : objectTriangles) {
                if (triangleHit != triangle) {
                    glm::vec3 hitPoint;
                    doesHit = triangle.RayIntersectsTriangle(rayPoint.get(), light.get(), hitPoint);
                    if (doesHit) {
                        break;
                    }
                } else {
                    
                }
                
            }
            if (!doesHit) {
                directLight = directLight + sceneAreaLight.radiance;
            }
        }
     
        directLight = directLight / sceneAreaLight.numberOfLightPoints;      
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
