#include <array>
#include <string>

using namespace std;

static constexpr array<pair<int, const char*>, 13> arabic_to_roman{{{1000, "M"},
                                                                    {900, "CM"},
                                                                    {500, "D"},
                                                                    {400, "CD"},
                                                                    {100, "C"},
                                                                    {90, "XC"},
                                                                    {50, "L"},
                                                                    {40, "XL"},
                                                                    {10, "X"},
                                                                    {9, "IX"},
                                                                    {5, "V"},
                                                                    {4, "IV"},
                                                                    {1, "I"}}};

string ConvertArabicToRoman(int arabic) {
  string roman{};
  for (const auto& roman_arabic_pair : arabic_to_roman) {
    while (arabic >= roman_arabic_pair.first) {
      roman += roman_arabic_pair.second;
      arabic -= roman_arabic_pair.first;
    }
  }

  return roman;
}