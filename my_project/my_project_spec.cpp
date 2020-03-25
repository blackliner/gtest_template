#include <gtest/gtest.h>

#include "my_project.hpp"

TEST(First, test) {
  EXPECT_EQ("I", ConvertArabicToRoman(1));
}
