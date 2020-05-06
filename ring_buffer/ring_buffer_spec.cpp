#include <gtest/gtest.h>

#include "ring_buffer.hpp"

class TestFixture : public ::testing::Test {
 public:
  RingBuffer<int> ring_buffer{5};
};

TEST_F(TestFixture, IsEmpty) {
  EXPECT_TRUE(ring_buffer.empty());
}

TEST_F(TestFixture, Size) {
  EXPECT_EQ(ring_buffer.size(), 0);
}

TEST_F(TestFixture, OneElement) {
  ring_buffer.push_back(1);
  EXPECT_FALSE(ring_buffer.empty());
}

TEST_F(TestFixture, PushedElementEqualsFirstElement) {
  ring_buffer.push_back(4);
  EXPECT_EQ(ring_buffer[0], 4);
}

TEST_F(TestFixture, PushOneElementInFront) {
  ring_buffer.push_back(4);
  ring_buffer.push_front(3);
  EXPECT_EQ(ring_buffer[0], 3);
}

TEST_F(TestFixture, PopOneElementInFront) {
  ring_buffer.push_back(4);
  ring_buffer.push_front(3);
  auto elem = ring_buffer.pop_front();
  EXPECT_EQ(elem, 3);
}

TEST_F(TestFixture, PopOneElementAtBack) {
  ring_buffer.push_back(4);
  ring_buffer.push_front(3);
  auto elem = ring_buffer.pop_back();
  EXPECT_EQ(elem, 4);
}

TEST_F(TestFixture, PopOneElementInFrontFromEmpty) {
  EXPECT_ANY_THROW(ring_buffer.pop_front());
}

TEST_F(TestFixture, PopOneElementBackFromEmpty) {
  EXPECT_ANY_THROW(ring_buffer.pop_back());
}

TEST_F(TestFixture, CapacitySmallerThanSize) {
  for(auto i=0;i<=5;++i)
  {
    ring_buffer.push_back(i);
  }
  EXPECT_EQ(ring_buffer[0],1);
}



