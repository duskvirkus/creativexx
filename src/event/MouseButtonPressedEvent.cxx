#include "MouseButtonPressedEvent.hxx"

namespace creative {
namespace event {

MouseButtonPressedEvent::MouseButtonPressedEvent(int button)
    : MouseButtonEvent(button) {}

EventType MouseButtonPressedEvent::type() const {
  return MOUSE_BUTTON_PRESSED;
}

}  // namespace event
}  // namespace creative
