ADD_LIBRARY(roman_numerals roman_numerals.cpp)

ADD_EXECUTABLE (roman_numerals_spec roman_numerals_spec.cpp)
TARGET_LINK_LIBRARIES (
    roman_numerals_spec 
    PRIVATE roman_numerals 
    PRIVATE gtest_main)

#ADD_GTEST(roman_numerals_spec)