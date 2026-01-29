---
name: doctest-cmake
description: Set up doctest testing framework in CMake C++ projects and write tests colocated with implementation code
---

## What I Do

Guide setup and usage of the doctest single-header C++17 testing framework in CMake projects, with tests written directly in source files alongside the code they test.

## Setup Instructions

### 1. Verify doctest header exists

Ensure the doctest header is present at `third-party/doctest/doctest.h`. This file must already exist in the repository.

### 2. Create test runner entry point

Create `test_main.cpp` at project root:

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
```

This file provides doctest's `main()` function for the test executable.

### 3. Update CMakeLists.txt

Add a test executable target alongside your main target:

```cmake
# Main application (unchanged)
add_executable(your_app
    main.cpp
    your_source.cpp
)

# Test executable
add_executable(tests
    test_main.cpp
    your_source.cpp  # Same sources as main app
)

target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)
target_compile_definitions(tests PRIVATE ENABLE_DOCTEST)
```

Key points:
- Include the same source files in both targets
- Add `third-party` to include directories so `#include "doctest/doctest.h"` resolves
- Define `ENABLE_DOCTEST` only for the test target
- This allows conditional compilation of test code

## Writing Tests

### Location

Write tests in the `.cpp` file where the code is **defined** (the implementation file), not in headers where code is declared.

### Pattern

Add tests at the bottom of source files, guarded by `#ifdef ENABLE_DOCTEST`:

```cpp
// your_source.cpp

#include "your_source.h"

// Implementation code here
int add(int a, int b) {
    return a + b;
}

// Tests - only compiled when ENABLE_DOCTEST is defined
#ifdef ENABLE_DOCTEST
#include "doctest/doctest.h"

TEST_CASE("add function") {
    CHECK(add(2, 3) == 5);
    CHECK(add(-1, 1) == 0);
    CHECK(add(0, 0) == 0);
}

#endif // ENABLE_DOCTEST
```

### Why this pattern

- Tests live next to the code they test for easy maintenance
- `ENABLE_DOCTEST` guard prevents test code from being compiled into production binaries
- Avoids linker errors from multiple `main()` definitions
- No separate test directory structure needed

## Building and Running

```bash
cmake -B build
cmake --build build

./build/your_app   # Run application
./build/tests      # Run tests
```

## When to Use This Skill

- Setting up doctest in a new or existing CMake C++ project
- Adding tests to C++ source files
- Understanding the colocated test pattern with conditional compilation
