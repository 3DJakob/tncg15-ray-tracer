#include <iostream>
#include <string.h>
using namespace std;

class Direction {
  public:
    double inclination;
    double azimuth;

    Direction() {
      inclination = 1.0;
      azimuth = 1.0;
    }

    Direction(double inInclination, double inAzimuth) {
      inclination = inInclination;
      azimuth = inAzimuth;
    }

    std::string toString() {
        return "Inclination: " + to_string(inclination) + "\n Azimuth: " + to_string(azimuth);
    }

    
};

ostream& operator << (ostream &os, const Direction &s) {
    return (os << "Inclination: " << to_string(s.inclination) << " Azimuth: " << to_string(s.azimuth) << std::endl);
}
