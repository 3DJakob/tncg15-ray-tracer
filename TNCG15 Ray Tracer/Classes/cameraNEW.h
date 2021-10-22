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
#include <vector>
#include <thread>

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
    double height = 480;
    // int width = 640;
    double width = 480;

    double lastProgress = 0;

      void renderPortion(int startX, int stopX, int startY, int stopY, Point cameraPlaneY, Point cameraPlaneZ, int samples, vector<Triangle> triangles, AreaLight sceneAreaLight, int height, int width, Point pointOfInterest, Point position)
    {
        for (int i = startX; i <= stopX; i++)
        {
            for (int j = startY; j <= stopY; j++)
            {
                // 2 x 2 camera plane
                auto target = Point(
                    pointOfInterest.get().x + cameraPlaneY.get().x * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().x * ((j - (height / 2)) / height) * 2,
                    pointOfInterest.get().y + cameraPlaneY.get().y * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().y * ((j - (height / 2)) / height) * 2,
                    pointOfInterest.get().z + cameraPlaneY.get().z * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().z * ((j - (height / 2)) / height) * 2);

                Ray tempRay;

                ColorDbl resColor = ColorDbl(0, 0, 0);

                for (int i = 0; i < samples; i++)
                {
                    resColor = resColor + (tempRay.cast(position, target, triangles, sceneAreaLight, 23) / samples);
                }

                // completed++;
                // displayProgress((completed * 100) / (height * width));

                RGBApixel Temp = AnImage.GetPixel(i, j);
                Temp.Blue = resColor.b;
                Temp.Green = resColor.g;
                Temp.Red = resColor.r;
                AnImage.SetPixel(i, j, Temp);
            }
        }
    }

    void displayProgress(double progress)
    {
        if (progress - lastProgress > 5)
        {
            lastProgress = progress;
            cout << "#";
        }
    }

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

    int completed = 0;


    void render(vector<Triangle> triangles, AreaLight sceneAreaLight, int samples)
    {

        cout << "calc axis:" << endl;
        auto cameraPlaneY = getPerpendicularVector(pointOfInterest, position, pointOfInterestTop);
        Point cameraPlaneZ = pointOfInterestTop;

        AnImage.SetSize(width + 1, height + 1);
        AnImage.SetBitDepth(8);

        cout << "____________________" << endl;

        // thread quad1(renderPortion, 0, width / 2, 0, height / 2, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);
        // thread quad2(renderPortion, width / 2, width, 0, height / 2, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);
        // thread quad3(renderPortion, 0, width / 2, height / 2, height, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);
        // thread quad4(renderPortion, width / 2, width, height / 2, height, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);


        // quad1.join();
        // quad2.join();
        // quad3.join();
        // quad4.join();


        renderPortion(0, width, 0, height, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);
        // thread image(renderPortion, 0, width, 0, height, cameraPlaneY, cameraPlaneZ, samples, triangles, sceneAreaLight, height, width, pointOfInterest, position);
        // image.join();
        //        auto auto = AnImage.WriteToFile("/Users/jakob/coding/tncg15-ray-tracer/TNCG15\ Ray\ Tracer/sample.bmp");
        /// alex path: /Users/alex/coding/tncg15-ray-tracer/TNCG15\ Ray\ Tracer/sample.bmp
        auto test = AnImage.WriteToFile("/Users/jakob/coding/tncg15/TNCG15\ Ray\ Tracer/sample.bmp");

        cout << endl;

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
