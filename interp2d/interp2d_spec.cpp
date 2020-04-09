#include <gtest/gtest.h>
#include "interp2d.hpp"

TEST(test, throw_on_empty_grid) {
  const LookupPoint lookup{0.0F, 0.0F};
  const DataGrid grid{};
  EXPECT_ANY_THROW(Interpolate2D(grid, lookup)) << "Interpolate2D is not throwing even so the grid is empty";
}

TEST(test, single_point_in_grid_lookup_on_point) {
  const LookupPoint lookup{0.0F, 0.0F};
  const DataGrid grid{{0.42F}};
  EXPECT_EQ(Interpolate2D(grid, lookup), 0.42F);
}

TEST(test, single_point_in_grid_lookup_out_of_bounds) {
  const LookupPoint lookup{1.0F, 0.0F};
  const DataGrid grid{{0.42F}};
  EXPECT_ANY_THROW(Interpolate2D(grid, lookup));
}

TEST(test, single_point_in_grid_lookup_out_of_bounds_2) {
  const LookupPoint lookup{0.8F, 0.8F};
  const DataGrid grid{{0.42F}};
  EXPECT_ANY_THROW(Interpolate2D(grid, lookup));
}

TEST(test, two_points_in_horizontal_grid_interpolate1D_lookup_in_the_middle) {
  const LookupPoint lookup{0.5F, 0.0F};
  DataGrid grid{2};
  grid[0].resize(1);
  grid[1].resize(1);
  grid[0][0] = 0.42F;
  grid[1][0] = 6.42F;
  EXPECT_FLOAT_EQ(3.42F, Interpolate2D(grid, lookup));
}

TEST(test, two_points_in_horizontal_grid_interpolate1D) {
  const LookupPoint lookup{0.75F, 0.0F};
  DataGrid grid{2};
  grid[0].resize(1);
  grid[1].resize(1);
  grid[0][0] = 0.42F;
  grid[1][0] = 6.42F;
  const auto expected = grid[0][0] + (grid[1][0] - grid[0][0]) * lookup.first;
  EXPECT_FLOAT_EQ(expected, Interpolate2D(grid, lookup));
}

TEST(test, two_points_in_horizontal_grid_interpolate1D_not_in_x_eq_0) {
  const LookupPoint lookup{0.75F, 1.0F};
  DataGrid grid{2};
  grid[0].resize(2);
  grid[1].resize(2);
  grid[0][1] = 0.42F;
  grid[1][1] = 6.42F;
  const auto expected = grid[0][1] + (grid[1][1] - grid[0][1]) * fmod(lookup.first, 1);
  EXPECT_FLOAT_EQ(expected, Interpolate2D(grid, lookup));
}

TEST(test, three_points_in_horizontal_grid_interpolate1D) {
  const LookupPoint lookup{1.75F, 1.0F};
  DataGrid grid{3};
  grid[0].resize(2);
  grid[1].resize(2);
  grid[2].resize(2);
  grid[1][1] = 0.42F;
  grid[2][1] = 6.42F;
  const auto expected = grid[1][1] + (grid[2][1] - grid[1][1]) * fmod(lookup.first, 1);
  EXPECT_FLOAT_EQ(expected, Interpolate2D(grid, lookup));
}

TEST(test, two_points_in_vertical_grid_interpolate1D) {
  const LookupPoint lookup{0.0F, 0.5F};
  DataGrid grid{1};
  grid[0].resize(2);
  grid[0][0] = 0.42F;
  grid[0][1] = 6.42F;
  EXPECT_FLOAT_EQ(3.42F, Interpolate2D(grid, lookup));
}

TEST(test, four_points_in_2d_simple_case) {
  const LookupPoint lookup{0.5F, 0.5F};
  DataGrid grid{2};
  grid[0].resize(2);
  grid[1].resize(2);
  grid[0][1] = 0.0F;
  grid[1][1] = 0.0F;
  grid[1][0] = 0.0F;
  grid[0][0] = 1.0F;
  const auto expected = 0.25F;
  EXPECT_FLOAT_EQ(expected, Interpolate2D(grid, lookup));
}

TEST(test, four_points_in_2d_complex_case) {
  const LookupPoint lookup{0.75F, 0.25F};
  DataGrid grid{2};
  grid[0].resize(2);
  grid[1].resize(2);
  grid[0][0] = 1.0F;
  grid[0][1] = 1.0F;
  grid[1][0] = 0.0F;
  grid[1][1] = 2.0F;
  const auto expected = 0.625F;
  EXPECT_FLOAT_EQ(expected, Interpolate2D(grid, lookup));
}
//   1 ---- 2
//   |      |
//   1     0.5
//   |      |
//   1 ---- 0
// 1 * (1-0.75) + 0.5 * (1-0.25) = 0.625