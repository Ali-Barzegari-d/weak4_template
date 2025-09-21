#include <cassert>
#include <string>
#include "valref.hpp"

int main() {
    int a = 5;
    inc_by_value(a);
    assert(a == 5); // should stay unchanged (correct behavior for value)

    inc_by_ref(a);
    assert(a == 6); // should increase by 1

    std::string s1 = "Hi";
    append_value(s1);
    assert(s1 == "Hi"); // unchanged, since passed by value

    std::string s2 = "Hello";
    append_ref(s2);
    assert(s2 == "Hello!"); // should be modified in-place

    return 0;
}
