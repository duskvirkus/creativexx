cmake_minimum_required(VERSION 3.12)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build")

project(CreativeXX)
set(CMAKE_CXX_STANDARD 14)

set(GCC_FLAGS "-Werror -Wall -Wextra -Wpedantic")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_FLAGS}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Make GLFW
add_subdirectory(vendor/glfw)

# Torch
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
