#include "valref.hpp"

// BUG: value version does not modify caller variable (expected behavior)
void inc_by_value(int x) {
    x = x + 1; // but effect is not visible to caller
}

// BUG: reference version is incorrectly written (currently same as value)
void inc_by_ref(int& x) {
    int tmp = x;
    tmp = tmp + 1; // but we forgot to write back to x
}

// BUG: string versions
void append_value(std::string s) {
    s += "!"; // change is lost because passed by value
}

void append_ref(std::string& s) {
    std::string copy = s;
    copy += "!"; // modifying the copy, not the original
}
