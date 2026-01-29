cmake_minimum_required(VERSION 3.16)
project(factorial_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application executable
add_executable(factorial_app
    main.cpp
    factorial.cpp
)

target_include_directories(factorial_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Testing support
enable_testing()

# Create a test runner that provides main() for doctest
add_executable(factorial_tests
    test_main.cpp
    factorial.cpp
)

target_include_directories(factorial_tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
)

# Define ENABLE_DOCTEST to enable tests in the source files
target_compile_definitions(factorial_tests PRIVATE ENABLE_DOCTEST)

add_test(NAME factorial_tests COMMAND factorial_tests)
