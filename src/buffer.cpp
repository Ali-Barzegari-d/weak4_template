#include "buffer.hpp"

Buffer::Buffer(std::size_t n) : data_(nullptr), size_(n) {
    if (n > 0) {
        data_ = std::make_unique<int[]>(n);
        // صفر کردن عناصر برای اطمینان
        for (std::size_t i = 0; i < n; ++i) {
            data_[i] = 0;
        }
    }
}

std::size_t Buffer::size() const {
    return size_;
}

int& Buffer::operator[](std::size_t idx) {
    return data_[idx];
}

const int& Buffer::operator[](std::size_t idx) const {
    return data_[idx];
}
