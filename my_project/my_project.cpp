#include "my_project.hpp"

std::string ConvertArabicToRoman(int arabic) {
  std::string roman{};

  int factor_fifty{arabic / 50};
  if (factor_fifty > 0) {
    roman += "L";
    arabic -= 50;
  }

  int factor_ten{arabic / 10};
  arabic %= 10;
  for (int i{0}; i < factor_ten; ++i) {
    roman += "X";
  }

  int factor_five{arabic / 5};
  if (factor_five > 0) {
    roman += "V";
    arabic -= 5;
  }

  if (arabic == 4) {
    roman += "IV";
  } else {
    for (int i{0}; i < arabic; ++i) {
      roman += "I";
    }
  }

  return roman;
}
