
add_executable(interpolate.spec interpolate.spec.cxx)
target_include_directories(interpolate.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(interpolate.spec PRIVATE creativexx)
