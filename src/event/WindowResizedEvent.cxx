#include "WindowResizedEvent.hxx"

namespace creative {
namespace event {

WindowResizedEvent::WindowResizedEvent(unsigned int width, unsigned int height)
    : m_width(width), m_height(height) {}

EventType WindowResizedEvent::type() const {
  return WINDOW_RESIZED;
}

unsigned int WindowResizedEvent::width() const {
  return m_width;
}

unsigned int WindowResizedEvent::height() const {
  return m_height;
}

}  // namespace event
}  // namespace creative
