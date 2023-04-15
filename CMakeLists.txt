cmake_minimum_required(VERSION 3.23)
project(C___14__Matrices C)

set(CMAKE_C_STANDARD 99)

add_executable(C___14__Matrices main.c libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h libs/data_structures/array/array.c libs/data_structures/array/array.h libs/data_structures/string/string_.c libs/data_structures/string/string_.h libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h)
