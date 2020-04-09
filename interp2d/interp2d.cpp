#include "interp2d.hpp"
#include <cassert>
#include <cmath>

float Interpolate1D(std::vector<float> vec, int low_index, int high_index, float nachkomma) {
       
    return  (1.0F-nachkomma) * vec[low_index] + nachkomma * vec[high_index];  
}

float Interpolate2D(const DataGrid& data_grid, const LookupPoint&  lookup_point){
    //size_t y_dim = data_grid.size();
    //<<0.0, 1.0>, <0.0. 2.0>>
    //data_grid[0] = <0.0, 1.0>
    //x_values[0] = 0.0
    size_t x_dim = data_grid[0].size();
    auto x_values = data_grid[0];
    assert(lookup_point.first >= 0 && lookup_point.first < x_dim);

    float retVal{};

    size_t low_index = static_cast<size_t>(floor( lookup_point.first));
    size_t high_index = static_cast<size_t>(ceil(lookup_point.first));

    if (low_index <=  lookup_point.first && lookup_point.first <= high_index) {        
      float nachkomma = lookup_point.first - low_index;
      retVal = Interpolate1D(x_values, low_index, high_index, nachkomma);
    }

    return retVal;
} 