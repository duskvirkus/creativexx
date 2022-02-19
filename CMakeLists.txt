cmake_minimum_required(VERSION 3.12)


# Configure varibles
# set(BUILD_TYPE_DIR)
string(TOLOWER ${CMAKE_BUILD_TYPE} BUILD_TYPE_DIR)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/build/${BUILD_TYPE_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/${BUILD_TYPE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/${BUILD_TYPE_DIR}")

message("== CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("== CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("== CMAKE_LIBRARY_OUTPUT_DIRECTORY: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message("== CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

foreach(path ${CMAKE_PREFIX_PATH})
  message("== CMAKE_PREFIX_PATH - PATH: ${path}")
endforeach(path)

# Configure compiler


if(CMAKE_BUILD_TYPE STREQUAL "RELEASE")
  set(CMAKE_C_COMPILER "gcc")
  set(CMAKE_CXX_COMPILER "/usr/bin/g++")

  set(GCC_FLAGS "-O3")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_FLAGS}")
elseif(CMAKE_BUILD_TYPE STREQUAL "DEBUG")
  set(CMAKE_C_COMPILER "clang")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

  set(CLANG_FLAGS "-O0")
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CLANG_FLAGS}")
else()
  message(FATAL_ERROR "FATAL: Unsupported CMAKE_BUILD_TYPE!")
endif()

set(ALL_WARNING_FLAGS "-Werror -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${ALL_WARNING_FLAGS}")

# Setup Project

project(creativexx)
set(CMAKE_CXX_STANDARD 14)

# Make GLFW
add_subdirectory(vendor/glfw)

# OpenCV
# set(OpenCV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/opencv/bin")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Torch
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(examples)
