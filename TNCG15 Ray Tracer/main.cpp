
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
    cout << Point() << endl;
    
//    Triangle myTriangle(Point(), Point(1.0, 0.0, 0.0), Point(0.0, 0.0, 1.0));
//    cout << myTriangle.p1 << endl;
    
    Camera myCamera(Point(-1.0, 0.0, 0.0), Point(0.0, 0.0, 0.0), Point(0.0, 0.0, -1.0));
    cout << myCamera.position << endl;
    
    // assemble all objects
    Room myRoom;
    
    Tetrahedon myTetrahedon(Point(8.0, 3.0, -1.0));
    
    vector<Triangle> allTriangles = myTetrahedon.triangleList + myRoom.triangles;
    cout << allTriangles.size() << endl;
    
    //myRoom.triangles.insert( myRoom.triangles.end(), myTetrahedon.triangleList.begin(), myTetrahedon.triangleList.end() );
    //cout << myRoom.triangles.size() << endl;
    
//    for (Triangle i: myRoom.triangles)
//        cout << i.p1 << " " << i.p2 << " " << i.p3 << endl;
    
//    vector<Triangle> SceneTriangles(myRoom.triangles.size() + myTetrahedon.triangles.size());
//        merge(myRoom.triangles.begin(),
//              myRoom.triangles.end(),
//              myTetrahedon.triangles.begin(),
//              myTetrahedon.triangles.end(),
//              SceneTriangles.begin());
    

    AreaLight myAreaLight;
//    myCamera.render(myRoom.triangles);
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


