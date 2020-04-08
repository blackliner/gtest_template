#include <gtest/gtest.h>

#include "interp2d.hpp"

TEST(Interpolation, initial_point) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
  
  const LookupPoint lookup_point{0.0F, 0.0F};

  EXPECT_FLOAT_EQ(0.F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, second_point) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
  
  const LookupPoint lookup_point{0.0F, 1.0F};

  EXPECT_FLOAT_EQ(2.F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, interpolation_y_direction) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
  
  const LookupPoint lookup_point{0.0F, 0.5F};

  EXPECT_FLOAT_EQ(1.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, third_point) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};

  const LookupPoint lookup_point{1.0F, 0.0F};

  EXPECT_FLOAT_EQ(1.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, fourth_point) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};

  const LookupPoint lookup_point{1.0F, 1.0F};

  EXPECT_FLOAT_EQ(3.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, interpolate_between_third_and_fourth_point) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};

  const LookupPoint lookup_point{1.0F, 0.5F};

  EXPECT_FLOAT_EQ(2.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, interpolate_x_direction) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};

  const LookupPoint lookup_point{0.5F, 0.0F};

  EXPECT_FLOAT_EQ(0.5F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interpolation, interpolate_in_the_middle) {
  const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
  const LookupPoint lookup_point{0.5F, 0.5F};

  EXPECT_FLOAT_EQ(1.5F, Interpolate2D(data_grid, lookup_point));
}

// Verify result
TEST(Interp2D, FinalBoss) {
  DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
  LookupPoint lookup_point{0.8F, 0.4F};
  EXPECT_EQ(1.6F, Interpolate2D(data_grid, lookup_point));
}