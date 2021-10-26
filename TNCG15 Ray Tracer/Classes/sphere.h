//
//  sphere.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-25.
//

#ifndef sphere_h
#define sphere_h
#include "point.hpp"
#include "glm.hpp"
#include <cfloat>
#include "ColorDbl.h"

using namespace std;

class Sphere
{

public:
    Point position;
    double radius;
    
    ColorDbl color;
    float roughness = 1.0f;
    float emission = 0.0f;

    Sphere(){
        position = Point();
        radius = 1.0;
    }
    
    Sphere(Point inPosition, double inRadius)
    {
        position = inPosition;
        radius = inRadius;
    }

    bool RayIntersectsSphere(glm::vec3 start, glm::vec3 inDirection, glm::vec3 &outIntersectionPoint)
    {
        // inDirection = inDirection - start;
        
        float d1, d2;
        glm::vec3 direction = glm::normalize(inDirection);
        auto startPoint = start;
        // cout << "X: " << direction.x << " Y: " << direction.y << " Z: " << direction.z << endl;
        float a = glm::dot(direction, direction);
        float b = 2.0 * glm::dot(direction, (startPoint - position.get()));
        float c = glm::dot((startPoint - position.get()), (startPoint - position.get())) - pow(radius, 2);

        //Used for the quadratic eq.
        float discriminant = b * b - 4.0f * a * c;

        // No solution
        if (discriminant < 0.0f)
        {
            return false;
        }
        // One solution
        else if (discriminant < DBL_EPSILON)
        {
            d1 = -(b / 2.0f);
            outIntersectionPoint = startPoint + direction * d1 ; 
            return true;
        }
        // Two solutions
        else
        {
            d1 = -(b / 2.0f) + sqrt(pow((b / 2.0f), 2) - a * c);
            d2 = -(b / 2.0f) - sqrt(pow((b / 2.0f), 2) - a * c);

            if (d2 > 0.0f)
            {
                outIntersectionPoint = startPoint + direction * d2;
                return true;
            }
            else if (d1 > 0.0f)
            {
                outIntersectionPoint = startPoint + direction * d1;
                return true;
            }
            return false;
        }
    };
};

bool operator==(Sphere &s1, Sphere &s2)
{
    return (s1.position == s2.position && s1.radius == s2.radius) ? true : false;
}

bool operator!=(Sphere &s1, Sphere &s2)
{
    return (s1 == s2) ? false : true;
}

#endif /* sphere_h */
