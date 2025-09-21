#include <cassert>
#include "buffer.hpp"

int main() {
    Buffer buf(5);
    assert(buf.size() == 5);

    // all zero-initialized
    for (std::size_t i = 0; i < buf.size(); i++) {
        assert(buf[i] == 0);
    }

    buf[2] = 42;
    assert(buf[2] == 42);

    buf[4] = -7;
    assert(buf[4] == -7);

    return 0;
}
