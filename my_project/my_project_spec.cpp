#include <gtest/gtest.h>

#include "my_project.hpp"

TEST(First, test) {
  EXPECT_EQ(42, gimme_gedoens());
}