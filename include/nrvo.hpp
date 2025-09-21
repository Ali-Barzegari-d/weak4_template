#pragma once
#include <string>

// A simple class that tracks copy/move behavior
struct Tracer {
    std::string name;

    Tracer(std::string n);

    // copy & move
    Tracer(const Tracer& other);
    Tracer(Tracer&& other) noexcept;

    // destructor
    ~Tracer();
};

// TODO: Implement a function that *returns a Tracer by value*.
// This is designed to explore NRVO (Named Return Value Optimization).
Tracer make_tracer(const std::string& tag);
