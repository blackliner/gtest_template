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

TEST(Roman, convert_ten) {
  EXPECT_EQ("X", ConvertArabicToRoman(10));
}

TEST(Roman, convert_twelve) {
  EXPECT_EQ("XII", ConvertArabicToRoman(12));
}

TEST(Roman, convert_twentyone) {
  EXPECT_EQ("XXI", ConvertArabicToRoman(21));
}

TEST(Roman, convert_fifty) {
  EXPECT_EQ("L", ConvertArabicToRoman(50));
}

TEST(Roman, convert_sixtyseven) {
  EXPECT_EQ("LXVII", ConvertArabicToRoman(67));
}

TEST(Roman, convert_four) {
  EXPECT_EQ("IV", ConvertArabicToRoman(4));
}
