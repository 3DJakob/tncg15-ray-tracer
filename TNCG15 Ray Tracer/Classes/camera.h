//
//  camera.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-07.
//

#ifndef camera_h
#define camera_h
#include "EasyBMP.h"
#include "ray.h"

#include "point.hpp"
#include "triangle.h"
#include "glm.hpp"
#include "gtx/transform.hpp"
#include "gtx/rotate_vector.hpp"

class Camera
{
public:
    Point position;
    Point pointOfInterest;
    int fov = 90;
    int height = 480;
    // int width = 640;
    int width = 480;

    Camera(Point positionIn, Point pointOfInterestIn)
    {
        position = positionIn;
        pointOfInterest = pointOfInterestIn;
    };

    BMP AnImage;



    void getPerpendicular(Point p1, Point p2)
    {
        auto line = p1.get() - p2.get();
        cout << " X: " << line.x << " Y: " << line.y << " Z: " << line.z << "" << endl;
        
        glm::vec3 perpendicular = glm::vec3(line.y, line.x, line.z);
//        glm::vec3 perpendicular2 = glm::vec3(line.y, line.x, line.z);
        
        glm::vec3 perpendicular2 = glm::cross(line, perpendicular);
        
        
   
        
        cout << " X: " << perpendicular.x << " Y: " << perpendicular.y << " Z: " << perpendicular.z << "" << endl;
        cout << " X: " << perpendicular2.x << " Y: " << perpendicular2.y << " Z: " << perpendicular2.z << "" << endl;
        
    }

    void render(Triangle triangles[])
    {
        
        cout << "calc axis:" << endl;
        getPerpendicular(position, pointOfInterest);
        
        AnImage.SetSize(width, height);
        AnImage.SetBitDepth(8);

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                // 2 x 2 camera plane
//                auto target = Point(pointOfInterestIn.x +)

//                    Ray tempRay(position, );

                //                auto color = Ray.triangleHit.material;

                RGBApixel Temp = AnImage.GetPixel(i, j);
                Temp.Blue = 255;
                Temp.Green = 255;
                Temp.Red = 0;
                AnImage.SetPixel(i, j, Temp);
            }
        }

        auto test = AnImage.WriteToFile("/Users/jakob/coding/tncg15/TNCG15\ Ray\ Tracer/fooo.bmp");
        if (test)
        {
            cout << "success!" << endl;
        }
        else
        {
            cout << "fail" << endl;
        }

        cout << "done" << endl;
        cout << AnImage.TellWidth() << " x " << AnImage.TellHeight()
             << " at " << AnImage.TellBitDepth() << " bpp" << endl;
    };

private:
};

#endif /* camera_h */
