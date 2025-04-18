cmake_minimum_required(VERSION 3.10)
project(cpp_playground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS     OFF)

add_executable(playground
    src/main.cpp
)

target_compile_options(playground PRIVATE
    -Wall
    -Wextra
    -pedantic
)

target_include_directories(playground PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
