#include <gtest/gtest.h>

#include "interp2d.hpp"


TEST(First, test_outside_low_x) {
 DataGrid data_grid{{0.0,1.0}};
 LookupPoint lookup_point{-1.0F, 1.0F};
 EXPECT_DEATH(Interpolate2D(data_grid, lookup_point), "");
}

TEST(First, test_outside_high_x) {
 DataGrid data_grid{{0.0,1.0}};
 LookupPoint lookup_point{2.0F, 1.0F};
 EXPECT_DEATH(Interpolate2D(data_grid, lookup_point), "");
}

TEST(First, test_left_boundary_x) {
 DataGrid data_grid{{0.0F ,1.0F}};
 LookupPoint lookup_point{0.0F, 0.0F};
 EXPECT_FLOAT_EQ(Interpolate2D(data_grid, lookup_point), 0.0F);
}

TEST(First, test_right_boundary_x) {
 DataGrid data_grid{{0.0F, 1.0F}};
 LookupPoint lookup_point{1.0F, 0.0F};
 EXPECT_FLOAT_EQ(Interpolate2D(data_grid, lookup_point), 1.0F);
}

TEST(First, test_interpolate_x) {
 DataGrid data_grid{{0.0F, 1.0F}};
 LookupPoint lookup_point{0.5F, 0.0F};
 EXPECT_FLOAT_EQ(Interpolate2D(data_grid, lookup_point), 0.5F);
}


TEST(First, test_interpolate_x_at_0_7) {
 DataGrid data_grid{{0.0F, 1.0F}};
 LookupPoint lookup_point{0.7F, 0.0F};
 EXPECT_FLOAT_EQ(Interpolate2D(data_grid, lookup_point), 0.7F);
}
