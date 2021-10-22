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

class Ray
{

public:
    Triangle triangleHit;
    Point rayPoint;
    double directLight;

    Ray()
    {
    }

    void CreateLocalCoordinateSystem(const glm::vec3 &normal, const glm::vec3 &incoming, glm::vec3 &axis1, glm::vec3 &axis2)
    {
        axis1 = glm::normalize(glm::cross(normal, incoming));
        axis2 = glm::normalize(glm::cross(axis1, normal));
    }

    // Cast rays untill color returns
    ColorDbl cast(Point _startPoint, Point direction, vector<Triangle> triangles, AreaLight sceneAreaLight, int depth, float importance)
    {
        triangleHit = triangles[0];
        startPoint = _startPoint.get();

        double minDist = 9999;
        glm::vec3 hitLocation;

        for (Triangle triangle : triangles)
        {
            auto res = glm::vec3();
            //            cout << direction << endl;
            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
            if (doesHit && (res.length() < minDist))
            {
                //                cout << "Hit: " << Point(res.x, res.y, res.z) << endl;
                minDist = res.length();
                triangleHit = triangle;
                hitLocation = res;
            }
        }
        rayPoint = Point(hitLocation.x, hitLocation.y, hitLocation.z);

        directLight = 0.0;

        // Calculate number of seen pointlights
        for (Point light : sceneAreaLight.lightPoints)
        {
            // Check if seen!
            //            auto objectTriangles = triangles. // No need to check for intersect with walls here...
            std::vector<Triangle> objectTriangles(triangles.begin(), triangles.end() - 20);
            bool doesHit = false;
            for (Triangle triangle : objectTriangles)
            {
                if (triangleHit != triangle)
                {
                    glm::vec3 hitPoint;
                    doesHit = triangle.RayIntersectsTriangle(rayPoint.get(), light.get(), hitPoint);
                    if (doesHit)
                    {
                        break;
                    }
                }
            }
            if (!doesHit)
            {
                directLight = directLight + sceneAreaLight.radiance;
            }
            else
            {
                // Is in shadow!
            }
        }

        directLight = directLight / sceneAreaLight.numberOfLightPoints;

        depth--;

        if (depth == 0)
        {
            return triangleHit.color * directLight * importance;
        }

        // russian roulette
        float p = 0.25;
        float random = (float)rand() / RAND_MAX;
        if (random < p)
        {
            return triangleHit.color * directLight * importance;
        }
        else
        {
            // run again!
            // res + triangleHit.color * directLight
            Ray tempRay;
            glm::vec3 axis1;
            glm::vec3 axis2;

            auto normal = triangleHit.rayNormal;
            auto incoming = _startPoint.get() - direction.get();

            tempRay.CreateLocalCoordinateSystem(normal, incoming, axis1, axis2);

            glm::vec3 outgoing = glm::vec3(0.0, 0.0, 0.0);
            
            if (triangleHit.roughness == 0.0) {
                // Perfect reflection
                outgoing = normal * glm::dot(normal, incoming);
                outgoing = outgoing - axis2 * glm::dot(incoming, axis2);
            } else {
                outgoing = normal * ((float)rand() / RAND_MAX);
                outgoing = outgoing + axis1 * ((float)rand() / RAND_MAX - 0.5f) * 2.0f;
                outgoing = outgoing + axis2 * ((float)rand() / RAND_MAX - 0.5f) * 2.0f;
            }

            // .cast() wants a target in 3d space not a direction
            outgoing = rayPoint.get() + outgoing;
            
            rayPoint.add( outgoing * -0.001f);

            auto color = tempRay.cast(rayPoint, Point(outgoing.x, outgoing.y, outgoing.z), triangles, sceneAreaLight, depth, importance * 0.8);
            // return color;
            return triangleHit.roughness == 0.0 ? color : color * triangleHit.color + triangleHit.color * directLight * importance;
        }

        // return triangleHit.color * directLight;
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
