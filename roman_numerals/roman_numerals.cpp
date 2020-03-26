#include "roman_numerals.hpp"
#include <vector>

std::string ConvertIntToRoman(int input) {
  std::vector<int> a{10, 5, 4, 1};
  std::vector<std::string> b{"X", "V", "IV", "I"};

  std::string result{};
  for (size_t i = 0; i < a.size(); i++) {
    while (input >= a[i]) {
      result += b[i];
      input -= a[i];
    }
  }

  return result;
}
