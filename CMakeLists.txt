cmake_minimum_required(VERSION 3.23)
project(VectorLab C)

set(CMAKE_C_STANDARD 23)

add_executable(VectorLab main.c "libs/data_structures/vector/vector.c" "libs/data_structures/vector/vector.h")
