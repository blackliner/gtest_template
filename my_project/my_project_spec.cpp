#include <gtest/gtest.h>

#include "my_project.hpp"

TEST(RomanNumerals, GivenOneThenI) {
  EXPECT_EQ("I", romanize(1));
}

TEST(RomanNumerals, GivenTwoThenII) {
  EXPECT_EQ("II", romanize(2));
}

TEST(RomanNumerals, GivenThreeThenIII) {
  EXPECT_EQ("III", romanize(3));
}

TEST(RomanNumerals, GivenFourThenIV) {
  EXPECT_EQ("IV", romanize(4));
}

TEST(RomanNumerals, GivenFiveThenV) {
  EXPECT_EQ("V", romanize(5));
}

TEST(RomanNumerals, GivenSevenThenVII) {
  EXPECT_EQ("VII", romanize(7));
}

TEST(RomanNumerals, GivenEightThenVIII) {
  EXPECT_EQ("VIII", romanize(8));
}

TEST(RomanNumerals, GivenNineThenIX) {
  EXPECT_EQ("IX", romanize(9));
}

TEST(RomanNumerals, GivenTenThenX) {
  EXPECT_EQ("X", romanize(10));
}