#include <cmath>
#include <utility>
#include <vector>

using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;

float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point) {
  const auto x = lookup_point.first;
  const auto x_floor = floorl(x);
  const auto x_ceil = ceill(x);
  if(x_ceil > data_grid.size()-1){
    throw "Index out of range";
  }
  
  const auto y = lookup_point.second;
  const auto y_floor = floorl(y);
  const auto y_ceil = ceill(y);
  //if(y_ceil > data_grid[x_ceil].size()-1){
  //  throw "Index out of range";
  //}
  const auto slope_x_at_y_floor = (data_grid[x_ceil][y_floor] - data_grid[x_floor][y_floor]);
  const auto intercept_x_at_y_floor = data_grid[x_floor][y_floor];
  const auto grid_val_at_y_floor = (x-x_floor) * slope_x_at_y_floor + intercept_x_at_y_floor;

  const auto slope_x_at_y_ceil = (data_grid[x_ceil][y_ceil] - data_grid[x_floor][y_ceil]);
  const auto intercept_x_at_y_ceil = data_grid[x_floor][y_ceil];
  const auto grid_val_at_y_ceil = (x-x_floor) * slope_x_at_y_ceil + intercept_x_at_y_ceil;

  const auto slope_y = (grid_val_at_y_ceil - grid_val_at_y_floor);
  const auto intercept_y = grid_val_at_y_floor;
  const auto interpolated_value = (y-y_floor) * slope_y + intercept_y;
  
  return interpolated_value;
}
