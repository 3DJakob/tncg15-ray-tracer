
#include "point.hpp"
#include <vector>
#include "direction.hpp"
#include <iostream>
#include "glm.hpp"
#include "room.h"
#include "triangle.h"
#include "camera.h"
#include "Arealight.h"
#include "Tetrahedon.h"


using namespace std;
template <typename T>
std::vector<T> operator+(const std::vector<T> &A, const std::vector<T> &B)
{
    std::vector<T> AB;
    AB.reserve(A.size() + B.size());                // preallocate memory
    AB.insert(AB.end(), A.begin(), A.end());
    AB.insert(AB.end(), B.begin(), B.end());
    return AB;
}

template <typename T>
std::vector<T> &operator+=(std::vector<T> &A, const std::vector<T> &B)
{
    A.reserve(A.size() + B.size());                // preallocate memory without erase original data
    A.insert(A.end(), B.begin(), B.end());
    return A;
}


int main()
{
//    glm::vec4 Position = glm::vec4(glm::vec3(0.0), 1.0);
    cout << "Tracer myTracer" << endl;
    
//    Point p1 = Point(0.0, 0.0, 1.0);
//    Point p2 = Point(1.0, 0.0, 0.0);
//    Point p3 = Point(0.0, 1.0, 0.0);
//    Triangle t1 = Triangle(p1, p2, p3);
//    Triangle t2 = Triangle(p1, p2, p3);
//    if (t1 == t2) {
//        cout << "EQUAL" << endl;
//    }

//    cout << t1.rayNormal.x << t1.rayNormal.y << t1.rayNormal.z << endl;
    
    Camera myCamera(Point(-1.0, 0.0, 0.0), Point(0.0, 0.0, 0.0), Point(0.0, 0.0, -1.0));
    
    // assemble all objects
    Room myRoom;
    Tetrahedon myTetrahedon(Point(8.0, 3.0, -1.0));
    
    vector<Triangle> allTriangles = myTetrahedon.triangleList + myRoom.triangles;
    AreaLight myAreaLight;
    myCamera.render(allTriangles, myAreaLight, 4);
    
    
    
//    Ray myRay;
//    AreaLight myAreaLightTest;
//
//    myRay.cast(Point(0.0, 0.0, 0.0), Point(1.0, 0.0, 1.0), allTriangles, myAreaLightTest, 10);
//    glm::vec3 axis1;
//    glm::vec3 axis2;
//    
//    auto normal = glm::vec3(0.0, 0.0, 1.0);
//    auto incoming = glm::vec3(-1.0, 1.0, 3.0);
//
//    myRay.CreateLocalCoordinateSystem(normal, incoming, axis1, axis2);
//
//    auto outgoing = normal * glm::dot(normal, incoming);
//    cout << glm::dot(normal, incoming) << endl;
//    outgoing = outgoing - axis2 * glm::dot(incoming, axis2);
//    cout << " X: " << outgoing.x << " Y: " << outgoing.y << " Z: " << outgoing.z << endl;
    
    
//    cout << " X: " << axis1.x << " Y: " << axis1.y << " Z: " << axis1.z << endl;
//    cout << " X: " << axis2.x << " Y: " << axis2.y << " Z: " << axis2.z << endl;

    
    
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


