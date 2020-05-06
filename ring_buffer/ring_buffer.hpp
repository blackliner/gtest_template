
#include <vector>

template <typename T>
class RingBuffer {
 public:
  explicit RingBuffer(const std::size_t capacity) {
    m_data.reserve(capacity);
  }

  std::size_t capacity() {
    return m_data.capacity();
  }

  std::size_t size() {
    return m_data.size();
  }

  void push_back(const T element) {
    m_data.push_back(element);
  }

  T& operator[](const std::size_t index) {
    return m_data[index];
  }

 private:
//   size_t end{0U};
  std::vector<T> m_data;
};