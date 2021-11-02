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
#include <functional>
#include <thread>

#include "point.hpp"
#include "triangle.h"
#include "glm.hpp"
#include "gtx/transform.hpp"
#include "gtx/rotate_vector.hpp"
#include "sphere.h"

class Camera
{
public:
    Point position;
    Point pointOfInterest;
    Point pointOfInterestTop;
    int fov = 90;
    double height = 799;
    // int width = 640;
    double width = 799;

    double lastProgress = 0;

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

    static void renderPixel(int i, int j, int width, int height, int samples, vector<Triangle> triangles, vector<Sphere> spheres, AreaLight sceneAreaLight, ColorDbl &resColor, Point target, Point position, int depth)
    {

        // Unecessary to render pixels outside viewport
        if (i <= width)
        {
            Ray tempRay;

            for (int i = 0; i < samples; i++)
            {
                resColor = resColor + (tempRay.cast(position, target, triangles, spheres, sceneAreaLight, depth, 1.0) / samples);
            }
        }
    }

    void setImagePixel(int x, int y, ColorDbl color)
    {
        // cout << "RED: " << color.r << " GREEN: " << color.g << " BLUE " << color.b << endl;
        if (x < width)
        {
            RGBApixel Temp2 = AnImage.GetPixel(x, y);
            Temp2.Blue = color.b * 255;
            Temp2.Green = color.g * 255;
            Temp2.Red = color.r * 255;
            AnImage.SetPixel(x + 1, y, Temp2);
        }
    }

    Point getTarget(Point pointOfInterest, Point cameraPlaneY, Point cameraPlaneZ, int i, int j)
    {
        return Point(
            pointOfInterest.get().x + cameraPlaneY.get().x * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().x * ((j - (height / 2)) / height) * 2,
            pointOfInterest.get().y + cameraPlaneY.get().y * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().y * ((j - (height / 2)) / height) * 2,
            pointOfInterest.get().z + cameraPlaneY.get().z * ((i - (width / 2)) / width) * 2 + cameraPlaneZ.get().z * ((j - (height / 2)) / height) * 2);
    }

    void render(vector<Triangle> triangles, vector<Sphere> spheres, AreaLight sceneAreaLight, int samples, int depth)
    {

        cout << "calc axis:" << endl;
        auto cameraPlaneY = getPerpendicularVector(pointOfInterest, position, pointOfInterestTop);
        Point cameraPlaneZ = pointOfInterestTop;

        AnImage.SetSize(width + 1, height + 1);
        AnImage.SetBitDepth(24);

        int completed;

        cout << "____________________" << endl;

        for (int i = 0; i <= width; i = i + 4)
        {
            for (int j = 0; j <= height; j++)
            {

                auto target1 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i, j);
                auto target2 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 1, j);
                auto target3 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 2, j);
                auto target4 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 3, j);
                auto target5 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 4, j);
                auto target6 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 5, j);
                auto target7 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 6, j);
                auto target8 = getTarget(pointOfInterest, cameraPlaneY, cameraPlaneZ, i + 7, j);

                ColorDbl resColor1, resColor2, resColor3, resColor4, resColor5, resColor6, resColor7, resColor8;

                thread pixel1(renderPixel, i, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor1), target1, position, depth);
                thread pixel2(renderPixel, i + 1, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor2), target2, position, depth);
                thread pixel3(renderPixel, i + 2, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor3), target3, position, depth);
                thread pixel4(renderPixel, i + 3, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor4), target4, position, depth);
                thread pixel5(renderPixel, i + 4, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor5), target5, position, depth);
                thread pixel6(renderPixel, i + 5, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor6), target6, position, depth);
                thread pixel7(renderPixel, i + 6, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor7), target7, position, depth);
                thread pixel8(renderPixel, i + 7, j, width, height, samples, triangles, spheres, sceneAreaLight, ref(resColor8), target8, position, depth);

                pixel1.join();
                pixel2.join();
                pixel3.join();
                pixel4.join();
                pixel5.join();
                pixel6.join();
                pixel7.join();
                pixel8.join();

                completed = completed + 4;
                displayProgress((completed * 100) / (height * width));

                setImagePixel(i, j, resColor1);
                setImagePixel(i + 1, j, resColor2);
                setImagePixel(i + 2, j, resColor3);
                setImagePixel(i + 3, j, resColor4);
                setImagePixel(i + 4, j, resColor5);
                setImagePixel(i + 5, j, resColor6);
                setImagePixel(i + 6, j, resColor7);
                setImagePixel(i + 7, j, resColor8);
            }
        }

        //        auto auto = AnImage.WriteToFile("/Users/jakob/coding/tncg15-ray-tracer/TNCG15\ Ray\ Tracer/sample.bmp");
        // alex path: /Users/alex/coding/tncg15-ray-tracer/TNCG15\ Ray\ Tracer/sample.bmp
        auto test = AnImage.WriteToFile("/Users/jakob/coding/tncg15-ray-tracer/TNCG15\ Ray\ Tracer/sample.bmp");

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
