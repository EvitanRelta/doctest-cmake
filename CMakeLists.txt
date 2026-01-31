cmake_minimum_required(VERSION 3.16)
project(factorial_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application executable
add_executable(factorial_app
    main.cpp
    factorial.cpp
)

target_include_directories(factorial_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

# Disable doctest in main application
target_compile_definitions(factorial_app PRIVATE DOCTEST_CONFIG_DISABLE)

# Testing support
enable_testing()

# Create a test runner that provides main() for doctest
add_executable(tests
    test_main.cpp
    factorial.cpp
)

target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/third-party
)

add_test(NAME tests COMMAND tests)
