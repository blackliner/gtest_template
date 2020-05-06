#include <gtest/gtest.h>

#include "ring_buffer.hpp"

TEST(RingBuffer, check_capacity_of_ring_buffer_three) {
  RingBuffer<int> unit{3};
  EXPECT_EQ(3, unit.capacity());
}

TEST(RingBuffer, check_capacity_of_ring_buffer_five) {
  RingBuffer<int> unit{5};
  EXPECT_EQ(5, unit.capacity());
}

TEST(RingBuffer, check_size_of_empty_ring_buffer) {
  RingBuffer<int> unit{3};
  EXPECT_EQ(0, unit.size());
}

TEST(RingBuffer, add_one_element_into_ring_buffer) {
  RingBuffer<int> unit{3};
  unit.push_back(4);
  EXPECT_EQ(1, unit.size());
}

TEST(RingBuffer, call_last_element) {
  RingBuffer<int> unit{3};
  unit.push_back(4);
  EXPECT_EQ(4, unit.back());
}

TEST(RingBuffer, call_last_element_value_five) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  EXPECT_EQ(5, unit.back());
}

TEST(RingBuffer, call_two_elements_of_ring_buffer) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  unit.push_back(4);
  EXPECT_EQ(5, unit[0]);
  EXPECT_EQ(4, unit[1]);
  EXPECT_EQ(2, unit.size());
}

TEST(RingBuffer, call_two_elements_of_ring_buffer_by_at) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  unit.push_back(4);
  EXPECT_EQ(5, unit.at(0));
  EXPECT_EQ(4, unit.at(1));
  EXPECT_EQ(2, unit.size());
}

TEST(RingBuffer, out_of_boundry_throws_exception) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  EXPECT_THROW(unit.at(1), std::out_of_range);
}

TEST(RingBuffer, pop_back_returns_correct_value_and_reduces_size) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  EXPECT_EQ(5, unit.pop_back());
  EXPECT_EQ(0, unit.size());
}

TEST(RingBuffer, two_times_pop_back_returns_correct_value_and_reduces_size) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  unit.push_back(4);
  EXPECT_EQ(4, unit.pop_back());
  EXPECT_EQ(1, unit.size());
}

TEST(RingBuffer, pop_back_throws_when_empty) {
  RingBuffer<int> unit{3};
  EXPECT_THROW(unit.pop_back(), std::out_of_range);
}

TEST(RingBuffer, pop_back_deletes_element) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  unit.pop_back();
  unit.push_back(4);
  EXPECT_EQ(4, unit[0]);
}

TEST(RingBuffer, check_empty) {
  RingBuffer<int> unit{3};
  EXPECT_TRUE(unit.empty());
  unit.push_back(3);
  EXPECT_FALSE(unit.empty());
}

TEST(RingBuffer, pop_front) {
  RingBuffer<int> unit{3};
  unit.push_back(3);
  EXPECT_EQ(3, unit.pop_front());
  EXPECT_TRUE(unit.empty());
}

TEST(RingBuffer, pop_front_complex) {
  RingBuffer<int> unit{3};
  unit.push_back(3);
  unit.push_back(4);
  EXPECT_EQ(3, unit.pop_front());
  EXPECT_EQ(4, unit.pop_front());
}

TEST(RingBuffer, pop_front_throws_when_empty) {
  RingBuffer<int> unit{3};
  EXPECT_THROW(unit.pop_front(), std::out_of_range);
}

TEST(RingBuffer, call_first_element_value_five) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  EXPECT_EQ(5, unit.front());
}

TEST(RingBuffer, call_first_element_after_pop_front) {
  RingBuffer<int> unit{3};
  unit.push_back(5);
  unit.push_back(4);
  unit.pop_front();
  EXPECT_EQ(4, unit.front());
}