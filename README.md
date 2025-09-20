# CSI2372 — Week 4 Lab Handout

**Topic:** ODR • Value vs Reference Semantics • NRVO • Dangling References • Smart Pointers • RAII  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---
## 1. Overview

In this lab you will practice advanced C++ concepts related to compilation/linking rules, ownership models, and deterministic lifetime. You will design small programs that highlight ODR pitfalls, explore value vs reference semantics, and implement RAII wrappers.

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

1. Write a header that incorrectly defines a function (`int add(int,int)`).
2. Include it in two different `.cpp` files and attempt to link.
3. Observe the linker error.
4. Fix the problem by moving the definition into a `.cpp` file or marking it `inline`.

---
## 4. Task B – Value vs Reference Parameters

1. Implement two versions of a function:
   ```cpp
   void inc_by_value(int x);
   void inc_by_ref(int& x);
   ```
2. Show the effect of calling both with the same variable.
3. Extend with a large `std::string` argument to demonstrate copy vs `const&` efficiency.

---
## 5. Task C – NRVO and Move Semantics

1. Define a class `Tracer` with copy/move constructors printing messages.
2. Write a function returning a `Tracer` by value.
3. Observe whether the copy/move is elided (NRVO).
4. Explain the difference between elision and explicit move.

---
## 6. Task D – Dangling References

1. Write a function returning a reference to a local variable.
2. Run the program and observe undefined behavior.
3. Fix by returning by value or ensuring object lifetime.

---
## 7. Task E – Smart Pointers

1. Use `std::unique_ptr<int>`: transfer ownership with `std::move` and confirm that the original pointer becomes empty.
2. Repeat with `std::shared_ptr<int>` and show that both owners share the same resource.

---
## 8. Task F – RAII Wrapper

1. Implement a minimal RAII wrapper for a file handle.
2. Constructor opens a file, destructor closes it.
3. Demonstrate exception safety: show that the file is always closed, even if an exception occurs.

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