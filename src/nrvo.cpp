#include "nrvo.hpp"
#include <iostream>

// constructor
Tracer::Tracer(std::string n) : name(std::move(n)) {
    std::cout << "Constructed: " << name << "\n";
}

// copy constructor
Tracer::Tracer(const Tracer& other) : name(other.name) {
    std::cout << "Copied: " << name << "\n";
}

// move constructor
Tracer::Tracer(Tracer&& other) noexcept : name(std::move(other.name)) {
    std::cout << "Moved: " << name << "\n";
}

// destructor
Tracer::~Tracer() {
    std::cout << "Destroyed: " << name << "\n";
}


Tracer make_tracer(const std::string& tag) {
    Tracer t(tag);
    return t; 
}
