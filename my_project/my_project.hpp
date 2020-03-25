#include <string>
#include <vector>

std::vector<int32_t> values{900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
std::vector<std::string> letters{"CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

std::string convert_to_roman_numerals(int32_t arabic) {
  std::string roman{""};

  for (size_t index{0U}; index < values.size(); ++index) {
    while (arabic >= values[index]) {
      roman += letters[index];
      arabic -= values[index];
    }
  }

  return roman;
}
