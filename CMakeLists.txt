cmake_minimum_required(VERSION 3.15)
project(testcase-itelma C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(testcase-itelma
    src/main.c
    src/keypad.c
    src/tests.c
)

target_include_directories(testcase-itelma PRIVATE include)
