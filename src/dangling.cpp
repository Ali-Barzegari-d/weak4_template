#include "dangling.hpp"


std::string bad_ref() {
    std::string local = "oops";
    return local; // return by value = safe
}

std::string safe_value() {
    return "fixed";
}
