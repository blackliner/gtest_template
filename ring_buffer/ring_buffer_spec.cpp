#include <gtest/gtest.h>

#include "ring_buffer.hpp"

// Lars   Navigator
// Carlo  Driver
// Manu
// Ishan

class RingBufferFixture : public ::testing::Test {
 public:
  const size_t kAnyCapacity{3};
  const int kAnyValue{1};
  const int kAnyOtherValue{2};
  const int kAnyMyValue{3};
  const int kAnyLuluValue{4};

  RingBuffer ringbuffer{kAnyCapacity};
};

TEST_F(RingBufferFixture, initial_capacity) {
  EXPECT_EQ(kAnyCapacity, ringbuffer.capacity());
}

TEST_F(RingBufferFixture, initial_size) {
  EXPECT_EQ(0, ringbuffer.size());
  EXPECT_TRUE(ringbuffer.empty());
}

TEST_F(RingBufferFixture, push_back_on_empty_ring_buffer) {
  ASSERT_TRUE(ringbuffer.empty());

  ringbuffer.push_back(kAnyValue);

  EXPECT_EQ(1U, ringbuffer.size());
  EXPECT_FALSE(ringbuffer.empty());
}

TEST_F(RingBufferFixture, element_access) {
  ASSERT_TRUE(ringbuffer.empty());

  ringbuffer.push_back(kAnyValue);

  EXPECT_EQ(kAnyValue, ringbuffer[0]);
}

TEST_F(RingBufferFixture, push_back_twice_and_access_it) {
  ASSERT_TRUE(ringbuffer.empty());

  ringbuffer.push_back(kAnyValue);
  ringbuffer.push_back(kAnyOtherValue);

  ASSERT_EQ(2U, ringbuffer.size());
  EXPECT_EQ(kAnyValue, ringbuffer[0]);
  EXPECT_EQ(kAnyOtherValue, ringbuffer[1]);
}

TEST_F(RingBufferFixture, push_back_one_more_than_capacity) {
  ASSERT_EQ(3U, ringbuffer.capacity());

  ringbuffer.push_back(kAnyValue);
  ringbuffer.push_back(kAnyOtherValue);
  ringbuffer.push_back(kAnyMyValue);
  ringbuffer.push_back(kAnyLuluValue);

  EXPECT_EQ(3U, ringbuffer.size());
}

TEST_F(RingBufferFixture, push_back_one_more_than_capacity_access) {
  ASSERT_EQ(3U, ringbuffer.capacity());

  ringbuffer.push_back(1);
  ringbuffer.push_back(2);
  ringbuffer.push_back(3);
  ringbuffer.push_back(4);
  ASSERT_EQ(3U, ringbuffer.size());

  EXPECT_EQ(2, ringbuffer[0]);
  EXPECT_EQ(3, ringbuffer[1]);
  EXPECT_EQ(4, ringbuffer[2]);
}

TEST_F(RingBufferFixture, push_back_two_more_than_capacity_access) {
  ASSERT_EQ(3U, ringbuffer.capacity());

  ringbuffer.push_back(1);
  ringbuffer.push_back(2);
  ringbuffer.push_back(3);
  ringbuffer.push_back(4);
  ringbuffer.push_back(5);
  ASSERT_EQ(3U, ringbuffer.size());

  EXPECT_EQ(3, ringbuffer[0]);
  EXPECT_EQ(4, ringbuffer[1]);
  EXPECT_EQ(5, ringbuffer[2]);
}

TEST_F(RingBufferFixture, push_back_twice_plus_one_more_than_capacity_access) {
  ASSERT_EQ(3U, ringbuffer.capacity());

  ringbuffer.push_back(1);
  ringbuffer.push_back(2);
  ringbuffer.push_back(3);
  ringbuffer.push_back(4);
  ringbuffer.push_back(5);
  ringbuffer.push_back(6);
  ringbuffer.push_back(7);
  ASSERT_EQ(3U, ringbuffer.size());

  EXPECT_EQ(5, ringbuffer[0]);
  EXPECT_EQ(6, ringbuffer[1]);
  EXPECT_EQ(7, ringbuffer[2]);
}
