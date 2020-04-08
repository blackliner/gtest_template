#include "interp2d.hpp"

#include "math.h"


float Interpolate(double x1, double x2, double y1, double y2, double x_interpolation)
{
    double slopeBetween1and2point = (y2 - y1) / (x2 - x1);
    double constant=y2-slopeBetween1and2point*x2;
    double lookupPointZ1 = slopeBetween1and2point * x_interpolation + constant;
    return lookupPointZ1;
}



float Interpolate2D(const DataGrid& grid, const LookupPoint& point) {

    double point1_x{};
    double point3_x{1.0F};

    double point1_y{};
    double point2_y{1.0};
    double point1_z{grid.at(0).at(0)};
    double point2_z{grid.at(0).at(1)};

    double point3_y{};
    double point4_y{1.0};
    double point3_z{grid.at(1).at(0)};
    double point4_z{grid.at(1).at(1)};


    double z_interpolate_inx1=Interpolate(point1_y,point2_y,point1_z,point2_z,point.second);

    double z_interpolate_inx2=Interpolate(point3_y,point4_y,point3_z,point4_z,point.second);

    double z_interpolate=Interpolate(point1_x,point3_x,z_interpolate_inx1,z_interpolate_inx2,point.first);

    return z_interpolate;
}
