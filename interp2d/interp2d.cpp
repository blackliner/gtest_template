#include "interp2d.hpp"

#include <cmath>

static float Interpolate1D(const std::vector<float>& data_vector, const float lookup_point) {
  const auto left_index = static_cast<std::size_t>(lookup_point);
  const auto right_index = static_cast<std::size_t>(std::ceil(lookup_point));
  const auto vector_value_left = data_vector.at(left_index);
  const auto vector_vaule_right = data_vector.at(right_index);
  const auto diff_vector_values = vector_vaule_right - vector_value_left;
  const auto ratio = lookup_point - left_index;

  return vector_value_left + diff_vector_values * ratio;
}

float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point) {
  const float row{lookup_point.first};
  const float col{lookup_point.second};
  const auto left_index = static_cast<std::size_t>(row);
  const auto right_index = static_cast<std::size_t>(std::ceil(row));
  const auto left_value = Interpolate1D(data_grid.at(left_index), col);
  const auto right_value = Interpolate1D(data_grid.at(right_index), col);
  std::vector<float> oneD_vector{left_value, right_value};

  const auto ratio = row - left_index;

  return Interpolate1D(oneD_vector, ratio);
}