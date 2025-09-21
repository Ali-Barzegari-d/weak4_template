#pragma once
#include <string>

// Task: Analyze and fix functions to correctly show value vs reference semantics.

// This function is supposed to increase input by 1, but currently does nothing useful.
void inc_by_value(int x);

// This function is supposed to increase input by 1, but currently wrong.
void inc_by_ref(int& x);

// For strings: function should append "!" at the end.
void append_value(std::string s);
void append_ref(std::string& s);
