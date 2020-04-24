
add_library(
        CreativeXX
        SHARED
        Core/Entry.h
        Application/Application.cpp
        Application/Application.h
        )

target_include_directories(CreativeXX PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
