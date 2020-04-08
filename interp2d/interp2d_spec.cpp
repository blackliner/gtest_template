#include <gtest/gtest.h>

#include "interp2d.hpp"

// using DataGrid = std::vector<std::vector<float>>;
// using LookupPoint = std::pair<float, float>;
// float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point);

TEST(Interp2D, emptyGrid) {
  DataGrid grid{};
  LookupPoint point{};

  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, nTimesZeroGrid) {
  DataGrid grid{};
  grid.resize(3);
  LookupPoint point{0.F, 0.F};

  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, outOfBoundLookupXNegative) {
  DataGrid grid = CreateDataGrid();

  LookupPoint point{-1.F, 1.F};
  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, outOfBoundLookupYNegative) {
  DataGrid grid = CreateDataGrid();

  LookupPoint point{1.F, -1.F};
  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, outOfBoundLookupXPositive) {
  DataGrid grid = CreateDataGrid();

  LookupPoint point{1.2F, 1.F};
  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, outOfBoundLookupYPositive) {
  DataGrid grid = CreateDataGrid();

  LookupPoint point{1.0F, 1.3F};
  EXPECT_ANY_THROW(Interpolate2D(grid, point));
}

TEST(Interp2D, Boundary00) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.0F, 0.0F};
  EXPECT_EQ(0.0f, Interpolate2D(grid, point));
}

TEST(Interp2D, Boundary01) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.0F, 1.0F};
  EXPECT_EQ(2.0f, Interpolate2D(grid, point));
}

TEST(Interp2D, Boundary11) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{1.0F, 1.0F};
  EXPECT_EQ(3.0f, Interpolate2D(grid, point));
}

TEST(Interp2D, Boundary10) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{1.0F, 0.0F};
  EXPECT_EQ(1.0f, Interpolate2D(grid, point));
}

TEST(Interp2D, Middlex) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.5F, 0.0F};
  EXPECT_EQ(0.5F, Interpolate2D(grid, point));
}

TEST(Interp2D, Quaterx) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.25F, 1.0F};
  EXPECT_EQ(2.25F, Interpolate2D(grid, point));
}

TEST(Interp2D, MiddlexMiddley) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.5F, 0.5F};
  EXPECT_EQ(1.5F, Interpolate2D(grid, point));
}

TEST(Interp2D, FinalBoss) {
  DataGrid grid = CreateDataGrid();
  LookupPoint point{0.8F, 0.4F};
  EXPECT_EQ(1.6F, Interpolate2D(grid, point));
}