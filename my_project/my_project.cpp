#include "my_project.hpp"

#include <array>

std::string ConvertArabicToRoman(int arabic) {
  std::string roman{};
  std::array<int, 6> arabic_digits{50, 10, 9, 5, 4, 1};
  std::array<std::string, 6> roman_digits{"L", "X", "IX", "V", "IV", "I"};

  for (int i{0}; i < 6; ++i) {
    while (arabic >= arabic_digits[i]) {
      roman += roman_digits[i];
      arabic -= arabic_digits[i];
    }
  }

  return roman;
}
