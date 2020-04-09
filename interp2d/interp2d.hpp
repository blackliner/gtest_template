#include <cassert>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;

float Interpolate(const float first_value, const float second_value, const float weight) {
  return first_value + (second_value - first_value) * weight;
}

using Coordinate = std::pair<std::size_t, std::size_t>;

Coordinate CreateCoordinate(const float x, const float y) {
  return Coordinate{static_cast<int>(x), static_cast<int>(y)};
}
float GridAt(const DataGrid& grid, const Coordinate& coordinate) {
  return grid.at(coordinate.first).at(coordinate.second);
}

float Interpolate2D(const DataGrid& grid, const LookupPoint& lookup_point) {
  //   lu----ru
  //   |      |
  //   l-- v--r
  //   |      |
  //   ll----rl

  const auto left_lower = CreateCoordinate(std::floor(lookup_point.first), std::floor(lookup_point.second));
  const auto right_lower = CreateCoordinate(std::floor(lookup_point.first), std::ceil(lookup_point.second));
  const auto left_upper = CreateCoordinate(std::ceil(lookup_point.first), std::floor(lookup_point.second));
  const auto right_upper = CreateCoordinate(std::ceil(lookup_point.first), std::ceil(lookup_point.second));

  const auto value_left =
      Interpolate(GridAt(grid, left_lower), GridAt(grid, right_lower), fmod(lookup_point.second, 1));
  const auto value_right =
      Interpolate(GridAt(grid, left_upper), GridAt(grid, right_upper), fmod(lookup_point.second, 1));

  const auto value = Interpolate(value_left, value_right, fmod(lookup_point.first, 1));

  return value;
}