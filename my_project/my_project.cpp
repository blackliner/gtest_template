#include "my_project.hpp"

#include <map>

static std::map<int, std::string> dict{{10, "X"}, {5, "V"}};

void AppendIs(int count, std::string& s) {
  for (int i = count; i > 0; --i) {
    s.append("I");
  }
}
void foo(int remainder, std::string& roman_string) {
  if (remainder < 0) {
    roman_string.insert(0, "I");
  } else {
    AppendIs(remainder, roman_string);
  }
}

void bar(int i, int digit, std::string& roman_string){
    const int remainder = digit - i;
    roman_string.append(dict[i]);
    foo(remainder, roman_string);
}

std::string romanize(int digit) {
  std::string roman_string{};
  for (int c = 10; c>3; c=c-5){
      if (digit > c-2){
      bar(c, digit, roman_string);
      }
  }
  if (digit > 10-2) {
    bar(10, digit, roman_string);
  } else if (digit > 5-2) {
    bar(5, digit, roman_string);
  } else {
    AppendIs(digit, roman_string);
  }
  return roman_string;
}
