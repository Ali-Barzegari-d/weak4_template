cmake_minimum_required(VERSION 3.12)
project(csi2372_lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Task A: ODR ---
add_library(odr src/odr_x.cpp src/odr_y.cpp)
target_include_directories(odr PUBLIC include)

add_executable(odr_tests tests/odr_tests.cpp)
target_link_libraries(odr_tests PRIVATE odr)
add_test(NAME odr_tests COMMAND $<TARGET_FILE:odr_tests>)

# --- Task B: Value vs Reference ---
add_library(valref src/valref.cpp)
target_include_directories(valref PUBLIC include)

add_executable(valref_tests tests/valref_tests.cpp)
target_link_libraries(valref_tests PRIVATE valref)
add_test(NAME valref_tests COMMAND $<TARGET_FILE:valref_tests>)

# --- Task C: NRVO ---
add_library(nrvo src/nrvo.cpp)
target_include_directories(nrvo PUBLIC include)

add_executable(nrvo_tests tests/nrvo_tests.cpp)
target_link_libraries(nrvo_tests PRIVATE nrvo)
add_test(NAME nrvo_tests COMMAND $<TARGET_FILE:nrvo_tests>)

# --- Task D: Dangling References ---
add_library(dangling src/dangling.cpp)
target_include_directories(dangling PUBLIC include)

add_executable(dangling_tests tests/dangling_tests.cpp)
target_link_libraries(dangling_tests PRIVATE dangling)
add_test(NAME dangling_tests COMMAND $<TARGET_FILE:dangling_tests>)

# --- Task E: Smart Pointer Buffer ---
add_library(buffer src/buffer.cpp)
target_include_directories(buffer PUBLIC include)

add_executable(buffer_tests tests/buffer_tests.cpp)
target_link_libraries(buffer_tests PRIVATE buffer)
add_test(NAME buffer_tests COMMAND $<TARGET_FILE:buffer_tests>)

# --- Task F: RAII Wrapper ---
add_library(file_raii src/file_raii.cpp)
target_include_directories(file_raii PUBLIC include)

add_executable(file_raii_tests tests/file_raii_tests.cpp)
target_link_libraries(file_raii_tests PRIVATE file_raii)
add_test(NAME file_raii_tests COMMAND $<TARGET_FILE:file_raii_tests>)

# --- Enable CTest ---
include(CTest)
