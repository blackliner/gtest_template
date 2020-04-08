#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;

float Interpolate2D(const DataGrid& grid, const LookupPoint& lookup_point) {
  if (grid.empty()) {
    throw std::invalid_argument("expected non empty grid");
  }

  const auto x = lookup_point.first;
  const auto y = lookup_point.second;

  if (x < 0 || y < 0 || (x + 1) > grid.size() || (y + 1) > grid[0].size()) {
    throw std::invalid_argument("point out of bounds");
  }

  int floor_x = std::floor(x);
  int ceil_x = std::ceil(x);
  int floor_y = std::floor(y);
  int ceil_y = std::ceil(y);

  auto interpolated_bottom = grid[floor_x][floor_y] + x * (grid[ceil_x][floor_y] - grid[floor_x][floor_y]);
  auto interpolated_top = grid[floor_x][ceil_y] + x * (grid[ceil_x][ceil_y] - grid[floor_x][ceil_y]);

  auto interpolated = interpolated_bottom + y * (interpolated_top - interpolated_bottom);

  return interpolated;
}

DataGrid CreateDataGrid(size_t x = 2, size_t y = 2) {
  DataGrid grid{};
  grid.resize(x);
  for (auto& x_axis : grid) {
    x_axis.resize(y);
  }

  //    x  y
  grid[0][0] = 0.0F;  // writes 0.0F to x=0 and y=0
  grid[1][0] = 1.0F;  // writes 1.0F to x=1 and y=0
  grid[0][1] = 2.0F;  // writes 2.0F to x=0 and y=1
  grid[1][1] = 3.0F;  // writes 3.0F to x=1 and y=1

  return grid;
}