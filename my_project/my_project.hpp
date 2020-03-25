#include "string"
using namespace std;

std::string EvaluateNumber(int number, string base, string middle, string next) {
  switch (number % 10) {
    case 1:
      return base;
    case 2:
      return base + base;
    case 3:
      return base + base + base;
    case 4:
      return base + middle;
    case 5:
      return middle;
    case 6:
      return middle + base;
    case 7:
      return middle + base + base;
    case 8:
      return middle + base + base + base;
    case 9:
      return base + next;
    default:
      return "";
  }
}

std::string GetRoman(int number) {
  std::string result = "";
  int number_of_M = number / 1000;
  for (int i = 0; i < number_of_M; ++i) {
    result += "M";
  }
  result += EvaluateNumber(number / 100, "C", "D", "M");
  result += EvaluateNumber(number / 10, "X", "L", "C");
  result += EvaluateNumber(number / 1, "I", "V", "X");

  return result;
}
