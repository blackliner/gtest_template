#include <gtest/gtest.h>
#include "my_project.hpp"

TEST(First, test) {
  EXPECT_EQ(2+3, add(2,3));
}

TEST(Second, test) {
  EXPECT_EQ(true, false);
}