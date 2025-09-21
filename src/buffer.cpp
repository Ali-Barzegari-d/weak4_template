#include "buffer.hpp"

// TODO: Implement all methods

Buffer::Buffer(std::size_t n)
    : data_(nullptr), size_(0) {
    // TODO: allocate array of n ints (all zero-initialized) using unique_ptr
}

std::size_t Buffer::size() const {
    // TODO
    return 0;
}

int& Buffer::operator[](std::size_t idx) {
    // TODO
    static int dummy = 0;
    return dummy;
}

const int& Buffer::operator[](std::size_t idx) const {
    // TODO
    static int dummy = 0;
    return dummy;
}
