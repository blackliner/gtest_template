#include <cmath>
#include <utility>
#include <vector>

using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;

float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point) {
  const auto x = lookup_point.first;
  const auto x_floor = static_cast<size_t>(std::floor(x));
  const auto x_ceil = static_cast<size_t>(std::ceil(x));
  const auto slope_x = (data_grid[x_ceil][0] - data_grid[x_floor][0]);
  const auto intercept = data_grid[x_floor][0];
  return x * slope_x + intercept;
}
