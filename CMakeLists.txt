cmake_minimum_required(VERSION 3.10)
project(cpp_sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lin_alg)

add_executable(playground
    src/main.cpp
)

target_compile_options(playground PRIVATE
    -Wall
    -Wextra
    -pedantic
)

find_package(Eigen3 REQUIRED)

# this brings in include/lin_alg via the PUBLIC include_directories
target_link_libraries(playground
    PRIVATE lin_alg
            Eigen3::Eigen
)
