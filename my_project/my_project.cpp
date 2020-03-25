#include "my_project.hpp"

void appendBar(std::string& value, int number) {
  for (int i = 0; i < number; i++) {
    value += "I";
  }
}

std::string firstDigitToRoman(int num) {
  std::string ret{};
  if (num <= 3) {
    appendBar(ret, num);
  } else if (num == 4) {
    ret = "IV";
  } else if (num >= 5 && num < 9) {
    ret = "V";
    const auto reps = num % 5;
    appendBar(ret, reps);
  } else if (num == 9) {
    ret = "IX";
  }
  return ret;
}

std ::string numToRoman(int num) {
  std::string ret{};
  const auto module10 = num % 10;
  ret = firstDigitToRoman(module10);
  if (num >= 10 && num < 20) {
    ret = "X" + ret;
  }
  if (num >= 20) {
    for (int i = 0; i < num / 10; i++) {
      ret += "X";
    }
  }
  return ret;
}