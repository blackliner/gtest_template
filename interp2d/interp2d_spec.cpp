#include <gtest/gtest.h>

#include "interp2d.hpp"

TEST(Interp2D, DirectlyUseOriginValueZero) {
  const DataGrid data_grid{{0.0F}};
  const LookupPoint lookup_point{0.0F, 0.0F};
  EXPECT_EQ(0.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interp2D, DirectlyUseOriginValueOne) {
  const DataGrid data_grid{{1.0F}};
  const LookupPoint lookup_point{0.0F, 0.0F};
  EXPECT_EQ(1.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interp2D, DirectlyUseLookupPoint) {
  const DataGrid data_grid{{1.0F}, {2.0F}};
  // data_grid[0][0] == 1.0F;
  // data_grid[1][0] == 2.0F;
  //           x  y
  const LookupPoint lookup_point{1.0F, 0.0F};
  EXPECT_EQ(2.0F, Interpolate2D(data_grid, lookup_point));
}

TEST(Interp2D, InterpolateInX) {
  const DataGrid data_grid{{1.0F}, {2.0F}};
  // (0,0) -> 1
  // (1,0) -> 2
  // (0.6,0) -> 1.6
  const LookupPoint lookup_point{0.6F, 0.0F};
  EXPECT_EQ(1.6F, Interpolate2D(data_grid, lookup_point));
}









// 4 Points on Grid
// DataGrid data_grid{{1, 6}, {1, 3}};
//           x  y
// data_grid[0][0] == 1
// data_grid[0][1] == 6
// data_grid[1][0] == 1
// data_grid[1][1] == 3

// LookupPoint x0{0.0F, 0.0F};

// y
// ^
// y(1)
// y(0)|
// |
//  (x0)---(x1)-----> x



// 6 Points on Grid
// DataGrid data_grid{{1, 6}, {1, 3}, {5, 8}};
//           x  y
// data_grid[0][0] == 1
// data_grid[0][1] == 6
// data_grid[1][0] == 1
// data_grid[1][1] == 3
// data_grid[2][0] == 5
// data_grid[2][1] == 8


// Alternative: 6 Points on Grid
// DataGrid data_grid{{1, 6, 7}, {1, 3, 4}};
//           x  y
// data_grid[0][0] == 1
// data_grid[0][1] == 6
// data_grid[0][2] == 7
// data_grid[1][0] == 1
// data_grid[1][1] == 3
// data_grid[1][2] == 4


// 9 Points on Grid
// DataGrid data_grid{{1, 6, 7}, {1, 3, 4}, {10, 2.4, 9}};
//           x  y
// data_grid[0][0] == 1
// data_grid[0][1] == 6
// data_grid[0][2] == 7
// data_grid[1][0] == 1
// data_grid[1][1] == 3
// data_grid[1][2] == 4
// data_grid[2][0] == 10
// data_grid[2][1] == 2.4
// data_grid[2][2] == 9