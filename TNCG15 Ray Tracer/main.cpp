
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
    cout << "Tracer myTracer" << endl;
    
    Camera myCamera(Point(-1.0, 0.0, 0.0), Point(0.0, 0.0, 0.0), Point(0.0, 0.0, -1.0));
    
    // assemble all objects
    Room myRoom;
    Tetrahedon myTetrahedon(Point(8.0, 3.0, -1.0));
    vector<Sphere> allSpheres;
    
    allSpheres.push_back(Sphere(Point(8, -3, -1), 3, ColorDbl(255, 255, 255), 0.0));
    
    AreaLight myAreaLight;
    
    vector<Triangle> allTriangles = myTetrahedon.triangleList + myAreaLight.triangles + myRoom.triangles;
    myCamera.render(allTriangles, allSpheres, myAreaLight, 20 );
    
    return 0;
}


