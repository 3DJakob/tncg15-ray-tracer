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

class Camera {
public:
    Point position;
    Point pointOfInterest;
    int fov = 90;
    int height = 480;
    // int width = 640;
    int width = 480;
    
    
    Camera(Point positionIn, Point pointOfInterestIn){
        position = positionIn;
        pointOfInterest = pointOfInterestIn;
    };
    
    BMP AnImage;
    
    void render(Triangle triangles[]) {
        AnImage.SetSize(width,height);
        AnImage.SetBitDepth(8);
        
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
//                Ray tempRay();
                
//                auto color = Ray.triangleHit.material;
                
                
                RGBApixel Temp = AnImage.GetPixel(i,j);
                Temp.Blue = 255;
                Temp.Green = 255;
                Temp.Red = 0;
                AnImage.SetPixel(i, j, Temp);
            }
        }
        
        
        auto test = AnImage.WriteToFile("/Users/jakob/coding/tncg15/TNCG15\ Ray\ Tracer/fooo.bmp");
        if (test) {
            cout << "success!" << endl;
        } else {
            cout << "fail" << endl;
        }
        
        cout << "done" << endl;
        cout << AnImage.TellWidth() << " x " << AnImage.TellHeight()
        << " at " << AnImage.TellBitDepth() << " bpp" << endl;
    };
    
    
private:
};

#endif /* camera_h */
