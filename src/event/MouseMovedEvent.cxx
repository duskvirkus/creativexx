#include "MouseMovedEvent.hxx"

namespace creative {
namespace event {

MouseMovedEvent::MouseMovedEvent(float x, float y) : m_x(x), m_y(y) {}

EventType MouseMovedEvent::type() const {
  return MOUSE_MOVED;
}

float MouseMovedEvent::x() const {
  return m_x;
}

float MouseMovedEvent::y() const {
  return m_y;
}

}  // namespace event
}  // namespace creative
