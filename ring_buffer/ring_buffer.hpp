#include <cstdio>
#include <vector>

template <typename T>
class RingBuffer {
 public:
  explicit RingBuffer<T>(const std::size_t sz) : m_capacity(sz), m_size(0) {
    m_buffer.resize(m_capacity);
    m_tail = 0;
    m_head = 0;
  };

  bool empty() {
    return m_size == 0;
  };

  std::size_t size() {
    return m_size;
  }

  void push_back(T elem) {
    ++m_size;
    if (m_size > static_cast<int>(m_capacity)) {
      m_buffer[m_tail] = elem;
      m_tail = (m_tail + 1) % m_capacity;
      m_size = m_capacity;
      m_head = (m_head + 1) % m_capacity;
    } else {
      m_buffer[m_tail] = elem;
      m_tail++;
    }
  }

  void push_front(T elem) {
    if (m_head == 0) {
      m_head = m_capacity - 1;
    } else {
      m_head--;
    }
    ++m_size;
    m_buffer[m_head] = elem;
  }

  T pop_front() {
    if (empty()) {
      throw 1;
    }
    T elem = m_buffer[m_head];
    m_head++;
    --m_size;
    return elem;
  }

  T pop_back() {
    if (empty()) {
      throw 1;
    }
    T elem = m_buffer[m_tail - 1];
    m_tail--;
    --m_size;
    return elem;
  }

  T& operator[](const std::size_t index) {
    return m_buffer[(m_head + index) % m_capacity];
  }

 private:
  std::size_t m_capacity;  // capacity
  int m_size;
  std::vector<T> m_buffer;
  std::size_t m_tail, m_head;
};