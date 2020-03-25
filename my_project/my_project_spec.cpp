#include <gtest/gtest.h>

#include "my_project.hpp"

using TestAndExpected = std::pair<int, std::string>;

static const std::array<TestAndExpected, 20U> checks{
    std::make_pair(1, "I"),   std::make_pair(2, "II"),   std::make_pair(3, "III"),  std::make_pair(10, "X"),
    std::make_pair(20, "XX"), std::make_pair(5, "V"),    std::make_pair(15, "XV"),  std::make_pair(16, "XVI"),
    std::make_pair(100, "C"), std::make_pair(200, "CC"), std::make_pair(4, "IV"),   std::make_pair(9, "IX"),
    std::make_pair(50, "L"),  std::make_pair(70, "LXX"), std::make_pair(40, "XL"),  std::make_pair(90, "XC"),
    std::make_pair(500, "D"), std::make_pair(400, "CD"), std::make_pair(900, "CM"), std::make_pair(371, "CCCLXXI")};

class TestRN : public ::testing::TestWithParam<TestAndExpected> {};

TEST_P(TestRN, Instance) {
  const auto& test{GetParam().first};
  const auto& expected{GetParam().second};
  EXPECT_EQ(convert_to_roman_numerals(test), expected);
}

INSTANTIATE_TEST_SUITE_P(TestRomanNumber, TestRN, ::testing::ValuesIn(checks));
