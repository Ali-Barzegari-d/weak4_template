#include <cassert>
#include "dangling.hpp"

int main() {
    // bad_ref() is buggy, may crash or produce garbage -> student must fix
    // safe_value() should always return a valid string

    std::string s = safe_value();
    assert(!s.empty());        // must not be empty
    assert(s == "fixed");      // expected content after fix

    return 0;
}
