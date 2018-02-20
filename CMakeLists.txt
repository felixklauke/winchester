cmake_minimum_required(VERSION 3.9)
project(winchester)

set(CMAKE_CXX_STANDARD 17)

add_executable(winchester main.cpp src/DFA.cpp include/DFA.h)