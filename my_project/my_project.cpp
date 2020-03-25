#include "my_project.hpp"

std::string ConvertArabicToRoman(int arabic) {
  std::string roman{};

  int factor_ten{arabic / 10};
  int rest{arabic % 10};
  for (int i{0}; i < factor_ten; ++i) {
    roman += "X";
  }

  int factor_five{rest / 5};
  rest = rest % 5;
  for (int i{0}; i < factor_five; ++i) {
    roman += "V";
  }
  
  for (int i{0}; i < rest; ++i) {
    roman += "I";
  }

  return roman;
}
