cmake_minimum_required(VERSION 3.10)
project(lin_alg LANGUAGES CXX)

# Tell CMake we need at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Your library target
add_library(lin_alg
  src/mat_mul.cpp
)

# Public include dir so users do:
#   #include <lin_alg/mat_mul.h>
target_include_directories(lin_alg
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
