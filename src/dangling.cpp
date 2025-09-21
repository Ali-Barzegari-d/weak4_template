#include "dangling.hpp"

// BUG: local string goes out of scope -> dangling reference
const std::string& bad_ref() {
    std::string local = "oops";
    return local; // returning reference to destroyed object
}

// TODO: Implement safe_value so it safely returns a string
std::string safe_value() {
    // should return a valid string without dangling
    // hint: return by value
    return {}; // TODO: implement
}
