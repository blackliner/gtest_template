#include <gtest/gtest.h>

#include "roman_numerals.hpp"

TEST(RomanNumerals, convert_1) {
  std::string out = ConvertIntToRoman(1);

  EXPECT_EQ("I", out);
}

TEST(RomanNumerals, convert_2) {
  std::string out = ConvertIntToRoman(2);

  EXPECT_EQ("II", out);
}

TEST(RomanNumerals, convert_3) {
  std::string out = ConvertIntToRoman(3);

  EXPECT_EQ("III", out);
}