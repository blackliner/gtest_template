#include <gtest/gtest.h>
#include "my_project.hpp"

// # Roman Numerals
// Given a positive integer number (eg 42) determine
// its Roman numeral representation as a String (eg "XLII").
// You cannot write numerals like IM for 999.
// Wikipedia states "Modern Roman numerals are written by
// expressing each arabic digit separately, starting with the
// leftmost digit, and skipping any digit with a value of zero."
// For example:
// * 1990 -> "MCMXC"  (1000 -> "M"  + 900 -> "CM" + 90 -> "XC")
// * 2008 -> "MMVIII" (2000 -> "MM" + 8 -> "VIII")
// * 99 -> "XCIX"     (90 -> "XC" + 9 -> "IX")
// * 47 -> "XLVII"    (40 -> "XL" + 7 -> "VII")
// The 'digits' are as follows:
// |            |              |               |               |
// |------------|--------------|---------------|---------------|
// |1 ->    "I" | 10 ->    "X" | 100 ->    "C" | 1000 ->    "M"|
// |2 ->   "II" | 20 ->   "XX" | 200 ->   "CC" | 2000 ->   "MM"|
// |3 ->  "III" | 30 ->  "XXX" | 300 ->  "CCC" | 3000 ->  "MMM"|
// |4 ->   "IV" | 40 ->   "XL" | 400 ->   "CD" | 4000 -> "MMMM"|
// |5 ->    "V" | 50 ->    "L" | 500 ->    "D" |               |
// |6 ->   "VI" | 60 ->   "LX" | 600 ->   "DC" |               |
// |7 ->  "VII" | 70 ->  "LXX" | 700 ->  "DCC" |               |
// |8 -> "VIII" | 80 -> "LXXX" | 800 -> "DCCC" |               |
// |9 ->   "IX" | 90 ->   "XC" | 900 ->   "CM" |               |

TEST(First, test) {
  EXPECT_EQ("I", numToRoman(1));
}

TEST(Second, test) {
  EXPECT_EQ("II", numToRoman(2));
}

TEST(Three, test) {
  EXPECT_EQ("III", numToRoman(3));
}

TEST(Four, test) {
  EXPECT_EQ("IV", numToRoman(4));
}

TEST(Five, test) {
  EXPECT_EQ("V", numToRoman(5));
}

TEST(Six, test) {
  EXPECT_EQ("VI", numToRoman(6));
}

TEST(Seven, test) {
  EXPECT_EQ("VII", numToRoman(7));
}

TEST(Eight, test) {
  EXPECT_EQ("VIII", numToRoman(8));
}

TEST(Nine, test) {
  EXPECT_EQ("IX", numToRoman(9));
}

TEST(Ten, test) {
  EXPECT_EQ("X", numToRoman(10));
}

TEST(Eleven, test) {
  EXPECT_EQ("XI", numToRoman(11));
}

TEST(Twelve, test) {
  EXPECT_EQ("XII", numToRoman(12));
}

TEST(Fifteen, test) {
  EXPECT_EQ("XV", numToRoman(15));
}

TEST(Eighteen, test) {
  EXPECT_EQ("XVIII", numToRoman(18));
}

TEST(Nineteen, test) {
  EXPECT_EQ("XIX", numToRoman(19));
}

TEST(Twenty, test) {
  EXPECT_EQ("XX", numToRoman(20));
}

TEST(TwentyOne, test) {
  EXPECT_EQ("XXI", numToRoman(21));
}