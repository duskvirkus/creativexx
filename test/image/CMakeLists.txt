
add_executable(Image.spec Image.spec.cxx)
target_include_directories(Image.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(Image.spec PRIVATE creativexx)
