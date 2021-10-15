
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
    cout << "Hello World" << endl;
    
    Point p1 = Point(-1.0, 0.0, 0.0);
    Point p2 = Point(-1.0, 1.0, 0.0);
    Point p3 = Point(-1.0, 1.0, 1.0);
    Triangle t1 = Triangle(p1, p2, p3);
    Triangle t2 = Triangle(p1, p2, p3);
    if (t1 == t2) {
        cout << "EQUAL" << endl;
    }
    
    Camera myCamera(Point(-1.0, 0.0, 0.0), Point(0.0, 0.0, 0.0), Point(0.0, 0.0, -1.0));
    
    // assemble all objects
    Room myRoom;
    Tetrahedon myTetrahedon(Point(8.0, 3.0, -1.0));
    
    vector<Triangle> allTriangles = myTetrahedon.triangleList + myRoom.triangles;
    AreaLight myAreaLight;
    myCamera.render(allTriangles, myAreaLight);
    

    
    
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


