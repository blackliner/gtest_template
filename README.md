# SME SDD Session 3: Ring Buffer

## Task description

Write a class that offers an interface to a ring buffer (also called circular or cyclic buffer). The term ring buffer refers to an area in memory which is used to store incoming data. When the buffer is filled, new data is written starting at the beginning of the buffer and overwriting the old (from [boost.org](https://www.boost.org/doc/libs/1_61_0/doc/html/circular_buffer.html)). It is a kind of sequence similar to `std::list` or `std::deque`. It supports random access iterators, constant time insert and erase operations at the beginning or the end of the buffer and interoperability with std algorithms.
The ring_buffer only allocates memory when created or when the capacity is adjusted explicitly.

<div style="text-align:center"><img src="https://www.boost.org/doc/libs/1_61_0/libs/circular_buffer/doc/images/circular_buffer.png" /></div>

## Usage example and API

To build and rund the tests:
```bash
mkdir -p build && cd build
cmake ..
cmake --build . --target test
```

```c++
RingBuffer<int> ring_buffer{3};  // Create a ring buffer with a capacity for 3 integers. Shall also support other types via template
ring_buffer.push_back(4);
ring_buffer.push_back(2);
ring_buffer.push_back(0);

ring_buffer[0] == 4;  // true
ring_buffer[1] == 2;  // true
ring_buffer[2] == 0;  // true

ring_buffer.push_back(5);  // 'shifts' everything forward.
ring_buffer[0] == 2;  // true
ring_buffer[1] == 0;  // true
ring_buffer[2] == 5;  // true

ring_buffer.pop_back(); // removes and returns ring_buffer[2], which currently equals 5
ring_buffer.pop_front(); // removes and returns ring_buffer[0], which currently equals 2

ring_buffer[0] == 0;  // true
```

Further API requirements (everything without comments should be self-explanatory)
```c++
template<typename T>
class RingBuffer{
  public:
    explicit RingBuffer(const std::size_t);
    void push_front(const T& element);
    void push_back(const T& element);
    T pop_front();  // Throws when empty
    T pop_back();  // Throws when empty
    T& front();  // Throws when empty
    T& back();  // Throws when empty
    T& at(std::size_t index);  // Checked access. Throws exception if out of bounds
    T& operator[](const std::size_t index);  // Unchecked, fast access. Undefined behavior if out of bounds.
    bool empty();
    bool full();
    std::size_t size();
    std::size_t capacity();
    void set_capacity(const std::size_t capacity);  // Does not change data if new capacity is larger than old. Cuts off from back if new capacity is smaller than old.
    void clear();
};
```

If you are super-fast, you can work on const reference accessors and (reverse) iterators, as described in the [boost documentation](https://www.boost.org/doc/libs/1_48_0/libs/circular_buffer/doc/circular_buffer.html).

## Comments

- For this assignment, you only need to test the template class for `int`. If you're interested to test more types, take a look at [templatized testing](https://github.com/google/googletest/blob/master/googletest/docs/advanced.md#typed-tests)
