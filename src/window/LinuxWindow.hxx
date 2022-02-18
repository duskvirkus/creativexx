#ifndef CREATIVEXX_LINUXWINDOW_H
#define CREATIVEXX_LINUXWINDOW_H

#include <GLFW/glfw3.h>
#include <string>

#include "../event/KeyPressedEvent.hxx"
#include "../event/KeyReleasedEvent.hxx"
#include "../event/MouseButtonPressedEvent.hxx"
#include "../event/MouseButtonReleasedEvent.hxx"
#include "../event/MouseMovedEvent.hxx"
#include "../event/MouseScrolledEvent.hxx"
#include "../event/WindowClosedEvent.hxx"
#include "../event/WindowResizedEvent.hxx"
#include "../log/Log.hxx"
#include "Window.hxx"

namespace creative {
namespace window {

class LinuxWindow : public Window {
 public:
  struct WindowData {
    std::string title;
    unsigned int width;
    unsigned int height;

    EventCallbackFunction event_callback;
  };

  LinuxWindow(std::string title, unsigned int width, unsigned int height);

  LinuxWindow(const LinuxWindow&) = delete;

  LinuxWindow(const LinuxWindow&&) = delete;

  LinuxWindow& operator=(const LinuxWindow&) = delete;

  LinuxWindow& operator=(const LinuxWindow&&) = delete;

  virtual ~LinuxWindow();

  void update() override;

  unsigned int width() const override;

  unsigned int height() const override;

  void set_event_callback(const EventCallbackFunction& callback) override;

 private:
  WindowData m_data;

  GLFWwindow* m_window;
};

}  // namespace window
}  // namespace creative

#endif  // CREATIVEXX_LINUXWINDOW_H
