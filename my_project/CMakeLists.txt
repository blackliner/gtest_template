ADD_LIBRARY(my_project my_project.cpp)

ADD_EXECUTABLE (my_project_spec my_project.cpp)
TARGET_LINK_LIBRARIES (
    my_project_spec 
    PRIVATE my_project 
    PRIVATE gtest_main)

ADD_GTEST(my_project_spec)