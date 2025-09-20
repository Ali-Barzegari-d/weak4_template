#pragma once

// ODR Exercise (slightly modified):
// Here we put a function *definition* in the header.
// When included in multiple .cpp files, this violates ODR.
//
// Task: Fix the violation without creating new files.

double multiply(double a, double b) { return a * b; } // <-- BUG: ODR violation
