
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
    return head;
  }

  void push_back(const T element) {
    m_data[head++] = element;
    head = head % capacity();
  }

  T& operator[](const std::size_t index) {
    return m_data[index];
  }

 private:
  size_t head{0U};
  //   size_t size{0U};
  std::vector<T> m_data;
};