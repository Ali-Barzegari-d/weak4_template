#pragma once
#include <string>

// Task: Fix dangling reference issues

// This function is buggy: it returns reference to a local variable.
// TODO: Fix the signature and/or implementation.
const std::string& bad_ref();

// This function should safely return the string.
std::string safe_value();
