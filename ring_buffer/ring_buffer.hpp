
#include <vector>

template <typename T>
class RingBuffer {
 public:
  explicit RingBuffer(const std::size_t capacity) {
    m_data.resize(capacity);
  }

  std::size_t capacity() {
    return m_data.size();
  }

  std::size_t size() {
    return end;
  }

  void push_back(const T element) {
    m_data[head++] = element;
    end = end % capacity();
  }

  T& operator[](const std::size_t index) {
    const auto index2 = (end + index) % capacity();
    return m_data[index2];
  }

 private:
  size_t begin{0U};
  size_t end{0U};
  //   size_t size{0U};
  std::vector<T> m_data;
};