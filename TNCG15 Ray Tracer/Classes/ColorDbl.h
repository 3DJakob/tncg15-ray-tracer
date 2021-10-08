//
//  ColorDbl.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-07.
//

#ifndef ColorDbl_h
#define ColorDbl_h

class ColorDbl {
public:
    double r;
    double g;
    double b;

    ColorDbl(){
        r = 255.0;
        g = 0.0;
        b = 0.0;
    };

    ColorDbl(double _r,double _g,double _b): r(_r), g(_g), b(_b) {}
};

#endif /* ColorDbl_h */
