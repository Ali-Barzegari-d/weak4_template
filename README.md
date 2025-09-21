# CSI2372 — Week 4 Lab Handout

**Topic:** ODR • Value vs Reference Semantics • NRVO • Dangling References • Smart Pointers • RAII  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---
## 1. Overview

In this lab you will practice advanced C++ concepts related to **compilation/linking rules**, **ownership models**, and **deterministic lifetime**. You will design small programs that highlight ODR pitfalls, explore value vs reference semantics, and implement RAII wrappers.

All work is **autograded via CI/CTest**. When the GitHub Actions build is green, you earn full marks.

---
## 2. Learning Objectives

By the end of this lab, you should be able to:

- Detect and fix ODR violations (multiple definitions, missing definitions, conflicting inline).
- Compare value vs reference parameter passing and explain observable behavior.
- Demonstrate NRVO and return-by-value efficiency.
- Identify dangling references and prevent undefined behavior.
- Use smart pointers (`unique_ptr`, `shared_ptr`) properly to manage ownership.
- Apply RAII principles to resource management.

---
## 3. Task A – ODR Violation Exploration

You are given code where a function is incorrectly defined in a header file.
When included from multiple .cpp files, this causes an ODR violation.

Fix the violation without adding new files.

Ensure the provided tests in odr_tests.cpp pass.

---
## 4. Task B – Value vs Reference Parameters

You are given buggy implementations in valref.cpp.

inc_by_value(int) should not modify the caller’s variable.

inc_by_ref(int&) should increase the caller’s variable by 1.

append_value(std::string) should not modify the caller’s string.

append_ref(std::string&) should append "!" to the caller’s string.

Currently, some of these functions are incorrectly implemented.

Fix the functions so that all provided tests in valref_tests.cpp pass

---
## 5. Task C – NRVO and Move Semantics

You are given a Tracer class that logs constructor, copy, and move operations.


Implement make_tracer(const std::string&) so it creates a local Tracer and returns it by value.

Do not use std::move in the return statement. Let the compiler apply NRVO or move semantics.

The tests check that a Tracer object is returned with the correct name.

---
## 6. Task D – Dangling References

The file contains buggy code that returns a reference to a local variable, causing undefined behavior.

Fix the implementation so no dangling reference occurs.

Ensure safe_value() returns a valid string.

---
## 7. Task E – Smart Pointers

Implement a class Buffer that manages a dynamic array of ints using smart pointers.

Complete the constructor so it allocates and zero-initializes an array using std::make_unique<int[]>.

Implement size() and operator[].

Ensure all tests in buffer_tests.cpp pass.

Avoid manual new/delete.

---
## 8. Task F – RAII Wrapper

Implement a minimal RAII wrapper for a **FILE**.

Your job:

Implement the constructor to open the file.

Implement the destructor to close the file.

Implement valid() and get().

Support move semantics but disable copying.

Tests ensure that the file is closed automatically when the object goes out of scope and that the contents can be verified afterward.

---
## 9. Building and Running

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

---
## 10. Grading

- **100% autograded**: Passing all provided tests yields full marks.
- No manual grading.

---
