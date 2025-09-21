#include <cassert>
#include "nrvo.hpp"

int main() {
    // When this function is correctly implemented,
    // compiler should apply NRVO or move semantics.

    Tracer t = make_tracer("demo");
    assert(!t.name.empty()); // must have a valid name
    assert(t.name == "demo");

    return 0;
}
