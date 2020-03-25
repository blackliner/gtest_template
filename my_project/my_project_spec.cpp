#include <gtest/gtest.h>

#include "my_project.hpp"

TEST(Roman, convert_one) {
  EXPECT_EQ("I", ConvertArabicToRoman(1));
}

TEST(Roman, convert_two) {
  EXPECT_EQ("II", ConvertArabicToRoman(2));
}

TEST(Roman, convert_three) {
  EXPECT_EQ("III", ConvertArabicToRoman(3));
}

TEST(Roman, convert_five) {
  EXPECT_EQ("V", ConvertArabicToRoman(5));
}

TEST(Roman, convert_six) {
  EXPECT_EQ("VI", ConvertArabicToRoman(6));
}