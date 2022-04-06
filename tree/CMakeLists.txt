cmake_minimum_required(VERSION 3.21)
project(tree C)

set(CMAKE_C_STANDARD 99)

add_executable(tree main.c tree_functions.c tree_functions.h stern_brocot_tree_functions.c stern_brocot_tree_functions.h additional.c additional.h)
