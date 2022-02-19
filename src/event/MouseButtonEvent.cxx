#include "MouseButtonEvent.hxx"

namespace creative {
namespace event {

MouseButtonEvent::MouseButtonEvent(int button) : m_button(button) {}

int MouseButtonEvent::button() const {
  return m_button;
}

}  // namespace event
}  // namespace creative
