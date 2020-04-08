#include <gtest/gtest.h>

#include "interp2d.hpp"

TEST(Interpolate2D, ZeroGrid_ZeroPoint) {
  const DataGrid data_grid{{0.0F}};
  const LookupPoint lookup_point{};
  EXPECT_FLOAT_EQ(0.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolate2D, expact_exeption_if_grid_is_empty) {
  const DataGrid data_grid{};
  const LookupPoint lookup_point{};
  EXPECT_THROW(Interpolate2D(data_grid, lookup_point), std::out_of_range);
}

TEST(Interpolate2D, LookUpPointEqualsZeroZero) {
  const DataGrid data_grid{{5.0F}};
  const LookupPoint lookup_point{0.0F, 0.0F};
  EXPECT_FLOAT_EQ(5.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolate2D, Interpolate1D) {
  const DataGrid data_grid{{0.0F, 2.0F}};
  const LookupPoint lookup_point{0.0F, 0.5F};
  EXPECT_FLOAT_EQ(1.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolate2D, Interpolate2D) {
  const DataGrid data_grid{{0.0F, 2.0F}, {0.0F, 4.0F}};
  const LookupPoint lookup_point{0.5F, 0.5F};
  EXPECT_FLOAT_EQ(1.5F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolate2D, Interpolate2DWith3Times2Grid) {
  const DataGrid data_grid{{0.0F, 1.0F}, {0.0F, 2.0F}, {0.0F, 4.0F}};
  const LookupPoint lookup_point{1.5F, 0.5F};
  EXPECT_FLOAT_EQ(1.5F, Interpolate2D(data_grid, lookup_point));
}