ADD_LIBRARY(my_project roman_numerals.cpp)

ADD_EXECUTABLE (my_project_spec roman_numerals_spec.cpp)
TARGET_LINK_LIBRARIES (
    my_project_spec 
    PRIVATE my_project 
    PRIVATE gtest_main)

ADD_GTEST(my_project_spec)