
add_executable(Logger.spec Logger.spec.cxx ../tools/CoutRedirect.cxx ../tools/CoutRedirect.hxx)
target_include_directories(Logger.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(Logger.spec PRIVATE creativexx)

add_executable(Log.spec Log.spec.cxx ../tools/CoutRedirect.cxx ../tools/CoutRedirect.hxx)
target_include_directories(Log.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(Log.spec PRIVATE creativexx)
