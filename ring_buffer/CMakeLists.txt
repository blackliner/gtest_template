ADD_LIBRARY(ring_buffer ring_buffer.cpp)

ADD_EXECUTABLE (ring_buffer_spec ring_buffer_spec.cpp)
TARGET_LINK_LIBRARIES (
    ring_buffer_spec 
    PRIVATE ring_buffer 
    PRIVATE gtest_main)

ADD_GTEST(ring_buffer_spec)