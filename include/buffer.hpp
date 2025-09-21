#pragma once
#include <memory>
#include <cstddef>

// Task: Implement Buffer using smart pointers
// The Buffer should manage a dynamic array of ints safely.

class Buffer {
public:
    // construct with given size, all elements initialized to zero
    explicit Buffer(std::size_t n);

    // return size
    std::size_t size() const;

    // element access (read/write)
    int& operator[](std::size_t idx);
    const int& operator[](std::size_t idx) const;

private:
    std::unique_ptr<int[]> data_; // smart pointer for array
    std::size_t size_{};
};
