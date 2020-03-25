#include "my_project.hpp"


std::string ConvertArabicToRoman(int arabic) {
  std::string roman{};

  int factor{0};
  int rest{0};
  factor = arabic / 5;
  rest = arabic % 5;

  for (int i{0}; i < factor; ++i) {
    roman += "V";
  }

  for (int i{0}; i < rest; ++i) {
    roman += "I";
  }

  return roman;
}
