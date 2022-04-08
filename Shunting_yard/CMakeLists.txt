cmake_minimum_required(VERSION 3.21)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack main.c stack.c stack.h tokens.c tokens.h Additional.c Additional.h Shunting_yard.c Shunting_yard.h)
