
#include "primitives/point.h"
#include "primitives/vector.h"
#include "primitives/direction.h"
#include <iostream>
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