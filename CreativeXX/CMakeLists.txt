
add_library(
        CreativeXX
        SHARED
        src/Core/Entry.h
        src/Application/Application.cpp
        src/Application/Application.h
        )

target_include_directories(CreativeXX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
