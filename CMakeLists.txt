cmake_minimum_required(VERSION 3.23)
project(LB_F C)

set(CMAKE_C_STANDARD 17)

add_executable(LB_F main.c Hash_func.c Hash_func.h Default_func.c Default_func.h Menu_func.c Menu_func.h LAB_specific.c LAB_specific.h)
