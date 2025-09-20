#include <cassert>
#include "odr.hpp"

double fx();
double fy();

int main() {
    assert(multiply(5.0, 2.0) == 10.0);
    assert(fx() == 6.0);
    assert(fy() == 6.0);

    return 0;
}
