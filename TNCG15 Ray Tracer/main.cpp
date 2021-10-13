
#include "point.hpp"
#include "vector.hpp"
#include "direction.hpp"
#include <iostream>
#include "glm.hpp"
#include "room.h"
#include "triangle.h"
#include "camera.h"
#include "Arealight.h"
#include "Tetrahedon.h"


using namespace std;


int main()
{
//    glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
    cout << "Hello World" << endl;
    cout << Point() << endl;
    
//    Triangle myTriangle(Point(), Point(1.0, 0.0, 0.0), Point(0.0, 0.0, 1.0));
//    cout << myTriangle.p1 << endl;
    
    Camera myCamera(Point(-1.0, 0.0, 0.0), Point(0.0, 0.0, 0.0), Point(0.0, 0.0, 1.0));
    cout << myCamera.position << endl;
    
    // assemble all objects
    Room myRoom;
    
    Tetrahedon myTetrahedon(Point(8.0, 0.0, 0.0));
    
    Triangle SceneTriangles[myTetrahedon.numberOfTriangles + myRoom.numberOfTriangles];
    for (int i = 0; i < myTetrahedon.numberOfTriangles + myRoom.numberOfTriangles; i++) {
        if (i < myTetrahedon.numberOfTriangles) {
            SceneTriangles[i] = myTetrahedon.triangles[i];
        } else {
            SceneTriangles[i] = myRoom.triangles[i - myTetrahedon.numberOfTriangles];
        }
    }
    
//    myCamera.render(myRoom.triangles);
    myCamera.render(SceneTriangles);
    
    
    AreaLight myAreaLight;
    
    
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
