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
        r = 0.0;
        g = 0.0;
        b = 255.0;
    };

    ColorDbl(double _r,double _g,double _b): r(_r), g(_g), b(_b) {}
};

ColorDbl operator*(const ColorDbl& col1, const ColorDbl& col2){
    return ColorDbl(col1.r * col2.r, col1.g * col2.g, col2.b * col1.b); 
}

ColorDbl operator*(const ColorDbl& col, const double& doubl){
    return ColorDbl(doubl * col.r, doubl * col.g, doubl * col.b);
}

ColorDbl operator+(const ColorDbl& col1, const ColorDbl& col2){
    return ColorDbl(col1.r + col2.r, col1.g + col2.g, col2.b + col1.b); 
}

#endif /* ColorDbl_h */
