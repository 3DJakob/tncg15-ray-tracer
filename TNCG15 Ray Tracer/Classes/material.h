//
//  Material.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-12.
//

#ifndef Material_h
#define Material_h

#include "ColorDbl.h"

class Material {
   
    
public:
    double diffuse;
    double specular;
    double translucence;
    colorDbl color;
    
    
    
    Material(double diffuse, double specular, double translucence, colorDbl color) : diffuse(diffuse), specular(specular), translucence(translucence), color(color) {
        
    }
    
    

private:

};

#endif /* Material_h */
