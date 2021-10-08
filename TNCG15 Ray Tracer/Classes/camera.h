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
    Point pointOfInterestTop;
    int fov = 90;
    double height = 1;
    // int width = 640;
    double width = 1;

    Camera(Point positionIn, Point pointOfInterestIn, Point pointOfInterestTopIn)
    {
        position = positionIn;
        pointOfInterest = pointOfInterestIn;
        pointOfInterestTop = pointOfInterestTopIn;
    };

    BMP AnImage;

    Point getPerpendicularVector(Point p1, Point p2, Point p3)
    {
        auto line1 = p2.get() - p1.get();
        auto line2 = p3.get() - p1.get();
        cout << " X: " << line1.x << " Y: " << line1.y << " Z: " << line1.z << "" << endl;
        cout << " X: " << line2.x << " Y: " << line2.y << " Z: " << line2.z << "" << endl;

        glm::vec3 perpendicular = glm::cross(line1, line2);

        cout << " X: " << perpendicular.x << " Y: " << perpendicular.y << " Z: " << perpendicular.z << "" << endl;
        return Point(perpendicular.x, perpendicular.y, perpendicular.z);
    }

    void render(Triangle triangles[])
    {

        cout << "calc axis:" << endl;
        auto cameraPlaneY = getPerpendicularVector(pointOfInterest, position, pointOfInterestTop);
        Point cameraPlaneZ = pointOfInterestTop;

        AnImage.SetSize(width + 1, height + 1);
        AnImage.SetBitDepth(8);

        for (int i = 0; i <= width; i++)
        {
            for (int j = 0; j <= height; j++)
            {
                // 2 x 2 camera plane
                auto target = Point(
                    pointOfInterest.get().x,
                    pointOfInterest.get().y + ((i - (width / 2)) / width)*2,
                    pointOfInterest.get().z + ((j - (height / 2)) / height)*2
                );
                
//                cout << "START: " << position << endl;
//                cout << "TARGET: " << target << endl;
                

                Ray tempRay(position, target, triangles);
                auto color = tempRay.triangleHit.color;

                RGBApixel Temp = AnImage.GetPixel(i, j);
                Temp.Blue = color.b;
                Temp.Green = color.g;
                Temp.Red = color.r;
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
