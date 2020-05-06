#include <cstddef>
#include <vector>
using namespace std;

class RingBuffer {
 public:
  RingBuffer(size_t capacity) : m_capacity(capacity) {
  }

  size_t capacity() const {
    return m_capacity;
  }

  size_t size() const {
    return m_data.size();
  }

  bool empty() const {
    return m_data.empty();
  }

  void push_back(const int value) {
    if (m_data.size() < m_capacity) {
      m_data.push_back(value);
    } else {
      m_data[m_oldest_entry_index] = value;
      m_oldest_entry_index = (m_oldest_entry_index +1 ) % m_capacity;
    }
  }

  int operator[](size_t index) const {
    return m_data[(m_oldest_entry_index + index) % (m_capacity)];
  }

 private:
  vector<int> m_data{};
  size_t m_capacity{};
  size_t m_oldest_entry_index{};
};