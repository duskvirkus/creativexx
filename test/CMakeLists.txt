
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test")

add_executable(working.spec working.spec.cxx)
target_include_directories(working.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../vendor/catch")

add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(window)
add_subdirectory(event)
