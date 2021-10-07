
#include "point.hpp"
#include "vector.hpp"
#include "direction.hpp"
#include <iostream>
#include "glm.hpp"

using namespace std;



int main()
{
    
    cout << "Hello World" << endl;

    // Point myPoint;
    Point myPoint(1.0,1.0,1.0);
    cout << myPoint << endl;

    // Direction myDirection;
    Direction myDirection(1.0,1.0);  // Create an object of MyClass
    cout << myDirection << endl;

    Vector myVector(myPoint,myPoint,myDirection);
    cout << "Vector: \n" << myVector << endl;
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
