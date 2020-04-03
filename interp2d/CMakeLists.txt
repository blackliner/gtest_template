ADD_LIBRARY(interp2d interp2d.cpp)

ADD_EXECUTABLE (interp2d_spec interp2d_spec.cpp)
TARGET_LINK_LIBRARIES (
    interp2d_spec 
    PRIVATE interp2d 
    PRIVATE gtest_main)

ADD_GTEST(interp2d_spec)
