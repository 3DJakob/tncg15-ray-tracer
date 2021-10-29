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
#include "sphere.h"
#include <math.h>

class Ray
{

public:
    Triangle triangleHit;
    Sphere sphereHit;
    Point rayPoint;
    double directLight;

    string hitType = "none"; // "sphere" | "triangle"

    Ray()
    {
    }

    void CreateLocalCoordinateSystem(const glm::vec3 &normal, const glm::vec3 &incoming, glm::vec3 &axis1, glm::vec3 &axis2)
    {
        axis1 = glm::normalize(glm::cross(normal, incoming));
        axis2 = glm::normalize(glm::cross(axis1, normal));
    }

    // Cast rays untill color returns
    ColorDbl cast(Point _startPoint, Point direction, vector<Triangle> triangles, vector<Sphere> spheres, AreaLight sceneAreaLight, int depth, float importance)
    {
        triangleHit = triangles[0];
        startPoint = _startPoint.get();

        double minDist = 9999;
        glm::vec3 hitLocation;

        for (Triangle triangle : triangles)
        {
            auto res = glm::vec3();
            bool doesHit = triangle.RayIntersectsTriangle(startPoint, direction.get() - startPoint, res);
            if (doesHit && (glm::distance(startPoint, res) < minDist))
            {
                hitType = "triangle";
                minDist = glm::distance(startPoint, res);
                triangleHit = triangle;
                hitLocation = res;
            }
        }

        for (Sphere sphere : spheres)
        {
            auto res = glm::vec3();
            bool doesHit = sphere.RayIntersectsSphere(startPoint, direction.get() - startPoint, res);
            if (doesHit && (glm::distance(startPoint, res) < minDist))
            {
                hitType = "sphere";
                minDist = glm::distance(startPoint, res);
                sphereHit = sphere;
                hitLocation = res;
            }
        }

        // Inverse square law
        // float radianceFalloff = 1 / pow((minDist + 1), 2);
        // float radianceFalloff = 1 / (minDist + 1);

        rayPoint = Point(hitLocation.x, hitLocation.y, hitLocation.z);

        directLight = 0.0;

        // Calculate number of seen pointlights
        bool doesHit = false;
        auto normal = hitType == "triangle" ? triangleHit.rayNormal : glm::normalize(hitLocation - sphereHit.position.get());

        if (glm::dot(sceneAreaLight.normal.get(), glm::normalize(hitLocation - sceneAreaLight.location.get())) > 0)
        {
            for (Point light : sceneAreaLight.lightPoints)
            {
                // if (glm::dot(normal, glm::normalize(light.get() - hitLocation)) > 0) {
                if (glm::dot(normal, glm::normalize(light.get() - hitLocation)) > 0)
                {
                    // Check if seen!
                    // No need to check for intersect with walls here... therefore -20 for increased preformance
                    std::vector<Triangle> objectTriangles(triangles.begin(), triangles.end() - 20);
                    for (Triangle triangle : objectTriangles)
                    {
                        if (hitType == "sphere" || triangleHit != triangle) // Hits triangle from a sphere
                        {
                            if (triangle.emission < 0.1)
                            { // Check that it is not triangles on the light itself
                                glm::vec3 hitPoint;
                                doesHit = triangle.RayIntersectsTriangle(rayPoint.get(), light.get() - rayPoint.get(), hitPoint);
                                if (doesHit && glm::distance(hitPoint, rayPoint.get()) > glm::distance(light.get(), rayPoint.get()))
                                { // If light is closer than the object covering it is not in shadow
                                    doesHit = false;
                                }
                                if (doesHit)
                                {
                                    break;
                                }
                            }
                        }
                    }

                    if (!doesHit)
                    {
                        for (Sphere sphere : spheres)
                        {
                            if (hitType == "triangle" || sphereHit != sphere) // Hits sphere
                            {
                                glm::vec3 hitPoint;
                                doesHit = sphere.RayIntersectsSphere(rayPoint.get(), light.get() - rayPoint.get(), hitPoint);
                                if (doesHit && glm::distance(hitPoint, rayPoint.get()) > glm::distance(light.get(), rayPoint.get()))
                                { // If light is closer than the object covering it is not in shadow
                                    doesHit = false;
                                }
                                if (doesHit)
                                {
                                    break;
                                }
                            }
                        }
                    }

                    if (!doesHit)
                    {
                        // directLight = directLight + sceneAreaLight.radiance / pow(glm::distance(light.get(), hitLocation), 0.5);
                        directLight = directLight + sceneAreaLight.radiance * 30 / pow(glm::distance(light.get(), hitLocation), 2);
                    }
                    else
                    {
                        // Is in shadow!
                    }
                }
            }
        } else {
            // cout << "no need to check" << endl;
        }

        directLight = directLight / sceneAreaLight.numberOfLightPoints;

        depth--;

        if (triangleHit.emission > 0.0)
        { // Hits light terminate!
            return triangleHit.color * triangleHit.emission * importance;
        }

        if (depth == 0)
        {
            if (hitType == "triangle")
            {
                return triangleHit.color * (directLight * importance) + triangleHit.color * triangleHit.emission * importance;
            }
            else if (hitType == "sphere")
            {
                return sphereHit.color * directLight * importance;
            }
        }

        // russian roulette
        float p = 0.25;
        float hitRougness = hitType == "triangle" ? triangleHit.roughness : sphereHit.roughness;
        if (hitRougness == 0.0)
        {
            p = 0.0;
        }
        float random = (float)rand() / RAND_MAX;
        if (random < p)
        {
            if (hitType == "triangle")
            {
                return (triangleHit.color * directLight * importance + triangleHit.emission * triangleHit.color * importance);
            }
            else if (hitType == "sphere")
            {
                return (sphereHit.color * directLight * importance);
            }
        }
        else
        {
            // run again!
            // res + triangleHit.color * directLight
            Ray tempRay;
            glm::vec3 axis1;
            glm::vec3 axis2;

            auto incoming = _startPoint.get() - direction.get();

            tempRay.CreateLocalCoordinateSystem(normal, incoming, axis1, axis2);

            glm::vec3 outgoing = glm::vec3(0.0, 0.0, 0.0);

            if ((hitType == "triangle" ? triangleHit.roughness : sphereHit.roughness) == 0.0)
            {
                // Perfect reflection
                outgoing = normal * glm::dot(normal, incoming);
                outgoing = outgoing - axis2 * glm::dot(incoming, axis2);
                importance = importance / 0.8; // Should not loose light in perfect reflection.
            }
            else
            {
                outgoing = normal * ((float)rand() / RAND_MAX);
                outgoing = outgoing + axis1 * ((float)rand() / RAND_MAX - 0.5f) * 2.0f;
                outgoing = outgoing + axis2 * ((float)rand() / RAND_MAX - 0.5f) * 2.0f;
            }

            // .cast() wants a target in 3d space not a direction
            outgoing = rayPoint.get() + outgoing;

            rayPoint.add(outgoing * -0.001f);

            auto color = tempRay.cast(rayPoint, Point(outgoing.x, outgoing.y, outgoing.z), triangles, spheres, sceneAreaLight, depth, importance * 0.8);
            // return color;
            if (hitType == "triangle")
            {
                return triangleHit.roughness == 0.0 ? (
                                                          color)
                                                    : (
                                                          color * triangleHit.color + triangleHit.color * directLight * importance + triangleHit.emission * triangleHit.color);
            }
            else if (hitType == "sphere")
            {
                return sphereHit.roughness == 0.0 ? color : (color * sphereHit.color + sphereHit.color * directLight * importance + sphereHit.emission * sphereHit.color);
            }
        }

        // will never happen hopefully
        return triangleHit.color * directLight * importance + triangleHit.emission * triangleHit.color;
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
