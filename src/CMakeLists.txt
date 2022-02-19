
add_library(
        creativexx
        SHARED
        application/Application.cxx
        application/Application.hxx
        core/entry.hxx
        core/init.cxx
        core/init.hxx
        image/Image.cxx
        image/Image.hxx
        log/Log.cxx
        log/Log.hxx
        log/Logger.cxx
        log/Logger.hxx
        math/interpolate.cxx
        math/interpolate.hxx
        renderer/Texture.cxx
        renderer/Texture.hxx
        window/Window.hxx
        window/LinuxWindow.cxx
        window/LinuxWindow.hxx
        event/Event.cxx
        event/Event.hxx
        event/EventType.hxx
        event/KeyEvent.cxx
        event/KeyEvent.hxx
        event/KeyReleasedEvent.cxx
        event/KeyReleasedEvent.hxx
        event/KeyPressedEvent.cxx
        event/KeyPressedEvent.hxx
        event/MouseButtonEvent.cxx
        event/MouseButtonEvent.hxx
        event/WindowClosedEvent.cxx
        event/WindowClosedEvent.hxx
        event/WindowResizedEvent.cxx
        event/WindowResizedEvent.hxx
        event/MouseButtonPressedEvent.cxx
        event/MouseButtonPressedEvent.hxx
        event/MouseButtonReleasedEvent.cxx
        event/MouseButtonReleasedEvent.hxx
        event/MouseMovedEvent.cxx
        event/MouseMovedEvent.hxx
        event/MouseScrolledEvent.cxx
        event/MouseScrolledEvent.hxx
        )

target_include_directories(creativexx INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/../include")

target_link_libraries(creativexx PRIVATE glfw)

target_link_libraries(creativexx PUBLIC "${TORCH_LIBRARIES}")
target_link_libraries(creativexx PUBLIC "${OpenCV_LIBS}")

target_include_directories(creativexx PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../vendor/glfw/include")
target_include_directories(creativexx PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../vendor/string-view-lite/include")
