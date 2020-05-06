#include <gtest/gtest.h>

#include "ring_buffer.hpp"

TEST(RingBuffer, construction_without_exception) {
  EXPECT_NO_THROW(RingBuffer<int> ring_buffer{3U});
}

TEST(RingBuffer, check_capacity) {
  RingBuffer<int> ring_buffer{3U};
  EXPECT_EQ(3U, ring_buffer.capacity());
}

TEST(RingBuffer, check_size) {
  RingBuffer<int> ring_buffer{3U};
  EXPECT_EQ(0U, ring_buffer.size());
}

TEST(RingBuffer, check_push_back) {
  RingBuffer<int> ring_buffer{3U};
  ring_buffer.push_back(25);
  EXPECT_EQ(1U, ring_buffer.size());
}

TEST(RingBuffer, check_access_operator) {
  RingBuffer<int> ring_buffer{3U};
  ring_buffer.push_back(0);
  ring_buffer.push_back(25);
  EXPECT_EQ(25, ring_buffer[1U]);
  EXPECT_EQ(2U, ring_buffer.size());
}

TEST(RingBuffer, check_overflow) {
  RingBuffer<int> ring_buffer{3U};
  ring_buffer.push_back(0);
  ring_buffer.push_back(1);
  ring_buffer.push_back(2);
  ring_buffer.push_back(3);
  EXPECT_EQ(1, ring_buffer[0U]);
  ring_buffer.push_back(4);
  EXPECT_EQ(2, ring_buffer[0U]);
}
