
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
    return m_size;  //(end - begin)) % capacity();
  }

  void push_back(const T element) {
    m_data[end++] = element;
    end = end % capacity();

    if (full()) {
      begin++;
      begin = begin % capacity();
    } else {
      m_size++;
    }
    
  }

  bool full() {
    return size() == capacity();  //
  }

  T& operator[](const std::size_t index) {
    const auto index2 = (begin + index) % capacity();

    return m_data[index2];
  }

 private:
  size_t begin{0U};
  size_t end{0U};
  size_t m_size{0U};
  std::vector<T> m_data;
};