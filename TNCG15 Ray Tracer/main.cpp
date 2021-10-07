
#include "point.hpp"
#include "vector.hpp"
#include "direction.hpp"
#include <iostream>
#include "glm.hpp"
#include "room.h"
#include "triangle.h"
#include "camera.h"
#include "EasyBMP.h"

using namespace std;



int main()
{
    BMP AnImage;
    AnImage.SetSize(640,480);
    AnImage.SetBitDepth(8);
    
    for (int i = 0; i < 640; i++) {
        for (int j = 0; j < 480; j++) {
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
    
    glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
    cout << "Hello World" << endl;
    
    Triangle myTriangle(Point, Point, Point);
    
    Camera myCamera;
    cout << myCamera.position << endl;
    
    
//    Room myRoom;

//    auto test = myRoom.foo;
//    cout << myRoom.points[0] << endl;

// hello?
//    glm::vec3 myPoint(1.0, 1.0, 1.0);
    Point myPoint;
    cout << myPoint << endl;

    // Direction myDirection;
    Direction myDirection(1.0,1.0);  // Create an object of MyClass
    cout << myDirection << endl;

//    Vector myVector(myPoint,myPoint,myDirection);
//    cout << "Vector: \n" << myVector << endl;
    return 0;
}
//int foo()
//{
//    glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
//    glm::mat4 Model = glm::mat4(1.0);
//    Model[4] = glm::vec4(1.0, 1.0, 0.0, 1.0);
//    glm::vec4 Transformed = Model * Position;
//    return 0;
//}
