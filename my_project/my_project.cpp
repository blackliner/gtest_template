#include "my_project.hpp"

std::string ConvertArabicToRoman(int arabic) {
  std::string roman{};

  while (arabic >= 50) {
    roman += "L";
    arabic -= 50;
  }
  while (arabic >= 10) {
    roman += "X";
    arabic -= 10;
  }
  while (arabic >= 9) {
    roman += "IX";
    arabic -= 9;
  }
  while (arabic >= 5) {
    roman += "V";
    arabic -= 5;
  }
  while (arabic >= 4) {
    roman += "IV";
    arabic -= 4;
  }
  while (arabic >= 1) {
    roman += "I";
    arabic -= 1;
  }

  return roman;
}
