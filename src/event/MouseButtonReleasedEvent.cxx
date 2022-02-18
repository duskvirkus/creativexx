#include "MouseButtonReleasedEvent.hxx"

namespace creative {
namespace event {

MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
    : MouseButtonEvent(button) {}

EventType MouseButtonReleasedEvent::type() const {
  return MOUSE_BUTTON_RELEASED;
}

}  // namespace event
}  // namespace creative
