
add_library(
        CreativeXX
        SHARED
        src/core.cpp
        src/core.h
        )

target_include_directories(CreativeXX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
