cmake_minimum_required(VERSION 3.15)
project(lab1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab1 main.c utility.h int_dyn_array.h string_dyn_array.h tests.h interface.h)