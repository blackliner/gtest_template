#include <utility>
#include <vector>


using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;

float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point);