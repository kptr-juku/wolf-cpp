cmake_minimum_required(VERSION 3.30)
project(WolfCpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wolf-cpp main.cc cpp_linux_syscalls.cc cpp_stdlib_test.cc)

