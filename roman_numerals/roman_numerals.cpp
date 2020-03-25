#include "roman_numerals.hpp"

std::string ConvertIntToRoman(int input) {
  std::string result{};
  while (input > 0) {
    result += "I";
    input--;
  }
  return result;
}
