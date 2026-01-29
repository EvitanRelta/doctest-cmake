cmake_minimum_required(VERSION 3.16)
project(factorial_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(factorial_app
    main.cpp
    factorial.cpp
)

target_include_directories(factorial_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
