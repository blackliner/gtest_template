#include <gtest/gtest.h>

#include "roman_numerals.hpp"

struct TestParameter {
  int arabic_number;
  std::string expected_roman;
};

class RomanNumeralsSpec : public ::testing::TestWithParam<TestParameter> {
 protected:
  RomanNumeralsSpec() {
  }
};

TEST_P(RomanNumeralsSpec, parameter_set) {
  auto param = GetParam();
  EXPECT_EQ(param.expected_roman, ConvertArabicToRoman(param.arabic_number));
}

INSTANTIATE_TEST_CASE_P(Default,
                        RomanNumeralsSpec,
                        ::testing::Values(TestParameter{1, "I"},
                                          TestParameter{2, "II"},
                                          TestParameter{3, "III"},
                                          TestParameter{4, "IV"},
                                          TestParameter{5, "V"},
                                          TestParameter{6, "VI"},
                                          TestParameter{7, "VII"},
                                          TestParameter{8, "VIII"},
                                          TestParameter{9, "IX"},
                                          TestParameter{10, "X"},
                                          TestParameter{14, "XIV"},
                                          TestParameter{25, "XXV"},
                                          TestParameter{39, "XXXIX"},
                                          TestParameter{40, "XL"},
                                          TestParameter{50, "L"},
                                          TestParameter{90, "XC"},
                                          TestParameter{100, "C"},
                                          TestParameter{400, "CD"},
                                          TestParameter{500, "D"},
                                          TestParameter{900, "CM"},
                                          TestParameter{1000, "M"},
                                          TestParameter{1990, "MCMXC"},
                                          TestParameter{2008, "MMVIII"},
                                          TestParameter{99, "XCIX"},
                                          TestParameter{47, "XLVII"},
                                          TestParameter{0, ""}
                                          ));