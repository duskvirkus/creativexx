
add_executable(KeyReleasedEvent.spec KeyReleasedEvent.spec.cxx)
target_include_directories(KeyReleasedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(KeyReleasedEvent.spec PRIVATE creativexx)

add_executable(KeyPressedEvent.spec KeyPressedEvent.spec.cxx)
target_include_directories(KeyPressedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(KeyPressedEvent.spec PRIVATE creativexx)

add_executable(MouseButtonPressedEvent.spec MouseButtonPressedEvent.spec.cxx)
target_include_directories(MouseButtonPressedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(MouseButtonPressedEvent.spec PRIVATE creativexx)

add_executable(MouseButtonReleasedEvent.spec MouseButtonReleasedEvent.spec.cxx)
target_include_directories(MouseButtonReleasedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(MouseButtonReleasedEvent.spec PRIVATE creativexx)

add_executable(MouseMovedEvent.spec MouseMovedEvent.spec.cxx)
target_include_directories(MouseMovedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(MouseMovedEvent.spec PRIVATE creativexx)

add_executable(MouseScrolledEvent.spec MouseScrolledEvent.spec.cxx)
target_include_directories(MouseScrolledEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(MouseScrolledEvent.spec PRIVATE creativexx)

add_executable(WindowClosedEvent.spec WindowClosedEvent.spec.cxx)
target_include_directories(WindowClosedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(WindowClosedEvent.spec PRIVATE creativexx)

add_executable(WindowResizedEvent.spec WindowResizedEvent.spec.cxx)
target_include_directories(WindowResizedEvent.spec PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../vendor/catch")
target_link_libraries(WindowResizedEvent.spec PRIVATE creativexx)
