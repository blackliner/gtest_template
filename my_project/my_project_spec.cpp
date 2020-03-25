#include <gtest/gtest.h>

#include "my_project.hpp"

TEST(Roman, first) {
  EXPECT_EQ("I", GetRoman(1));
}

TEST(Roman, second) {
  EXPECT_EQ("II", GetRoman(2));
}

TEST(Roman, third) {
  EXPECT_EQ("III", GetRoman(3));
}

TEST(Roman, fourth) {
  EXPECT_EQ("IV", GetRoman(4));
}

TEST(Roman, fifth) {
  EXPECT_EQ("V", GetRoman(5));
}

TEST(Roman, sixth) {
  EXPECT_EQ("VI", GetRoman(6));
}

TEST(Roman, seventh) {
  EXPECT_EQ("VII", GetRoman(7));
}
TEST(Roman, eight) {
  EXPECT_EQ("VIII", GetRoman(8));
}
TEST(Roman, ninth) {
  EXPECT_EQ("IX", GetRoman(9));
}

TEST(Roman, tenth) {
  EXPECT_EQ("X", GetRoman(10));
}

TEST(Roman, twenty) {
  EXPECT_EQ("XX", GetRoman(20));
}

TEST(Roman, fifty) {
  EXPECT_EQ("L", GetRoman(50));
}

TEST(Roman, ninety) {
  EXPECT_EQ("XC", GetRoman(90));
}

TEST(Roman, fourtyseven) {
  EXPECT_EQ("XLVII", GetRoman(47));
}

TEST(Roman, ninetynine) {
  EXPECT_EQ("XCIX", GetRoman(99));
}

TEST(Roman, hundred) {
  EXPECT_EQ("C", GetRoman(100));
}

TEST(Roman, hundredeleven) {
  EXPECT_EQ("CXI", GetRoman(111));
}

TEST(Roman, fourhundredfive) {
  EXPECT_EQ("CDV", GetRoman(405));
}

TEST(Roman, ninehundredninetynine) {
  EXPECT_EQ("CMXCIX", GetRoman(999));
}

TEST(Roman, _3999) {
  EXPECT_EQ("MMMCMXCIX", GetRoman(3999));
}

TEST(Roman, fourthousands) {
  EXPECT_EQ("MMMM", GetRoman(4000));
}