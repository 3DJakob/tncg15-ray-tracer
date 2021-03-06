//
//  ColorDbl.h
//  TNCG15 Ray Tracer
//
//  Created by Jakob Unnebäck on 2021-10-07.
//

#ifndef ColorDbl_h
#define ColorDbl_h

class ColorDbl
{
public:
    double r;
    double g;
    double b;

    ColorDbl()
    {
        r = 0.0;
        g = 0.0;
        b = 0.0;
    };

    ColorDbl(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {}
};

// ColorDbl * ColorDbl
ColorDbl operator*(const ColorDbl &col1, const ColorDbl &col2)
{
    return ColorDbl(col1.r * col2.r > 1.0 ? 1.0 : col1.r * col2.r,
                    col1.g * col2.g > 1.0 ? 1.0 : col1.g * col2.g,
                    col1.b * col2.b > 1.0 ? 1.0 : col1.b * col2.b);
}

// ColorDbl * double
ColorDbl operator*(const ColorDbl &col, const double &doubl)
{
    return ColorDbl(doubl * col.r > 1.0 ? 1.0 : col.r * doubl,
                    doubl * col.g > 1.0 ? 1.0 : col.g * doubl,
                    doubl * col.b > 1.0 ? 1.0 : col.b * doubl);
}
//  double * ColorDbl
ColorDbl operator*(const double &doubl, const ColorDbl &col)
{
    return col * doubl;
}

// ColorDbl + ColorDbl
ColorDbl operator+(const ColorDbl &col1, const ColorDbl &col2)
{
    return ColorDbl(col1.r + col2.r > 1.0 ? 1.0 : col1.r + col2.r,
                    col1.g + col2.g > 1.0 ? 1.0 : col1.g + col2.g,
                    col1.b + col2.b > 1.0 ? 1.0 : col1.b + col2.b);
}

// ColorDbl / int
ColorDbl operator/(const ColorDbl &col1, const int &number)
{
    return ColorDbl(
        col1.r / number > 1.0 ? 1.0 : col1.r / number,
        col1.g / number > 1.0 ? 1.0 : col1.g / number,
        col1.b / number > 1.0 ? 1.0 : col1.b / number);
}

ostream& operator<< (ostream &os, const ColorDbl &c) {
    return (os << "R: " << to_string(c.r) << " G: " << to_string(c.g) << " B: " << to_string(c.b)  << std::endl);
}

#endif /* ColorDbl_h */
