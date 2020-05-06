#include <cstdlib>
#include <stdexcept>
#include <vector>

template <typename T>
class RingBuffer {
 public:
  explicit RingBuffer(const std::size_t capacity) {
    m_values.reserve(capacity);
  }

  std::size_t capacity() {
    return m_values.capacity();
  }

  std::size_t size() {
    return m_size;
  }

  void push_back(const T& element) {
    ++m_size;
    m_values.push_back(element);
  }

  T& back() {
    return m_values.back();
  }

  T& front() {
    return m_values[m_start_index];
  }

  T& operator[](const std::size_t index) {
    return m_values[index];
  }

  T& at(const std::size_t index) {
    return m_values.at(index);
  }

  T pop_back() {
    if (m_size == 0) {
      throw std::out_of_range("Ring buffer is empty");
    }
    --m_size;
    const auto last{m_values.back()};
    m_values.pop_back();
    return last;
  }

  bool empty() {
    return m_size == 0U;
  }

  T pop_front() {
    if (m_size == 0) {
      throw std::out_of_range("Ring buffer is empty");
    }
    --m_size;
    return m_values[m_start_index++];
  }

 private:
  std::size_t m_size{};
  std::vector<T> m_values{};
  std::size_t m_start_index{};
};