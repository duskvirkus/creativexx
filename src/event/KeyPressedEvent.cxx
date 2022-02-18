#include "KeyPressedEvent.hxx"

namespace creative {
namespace event {

KeyPressedEvent::KeyPressedEvent(unsigned int key_code, bool repeat)
    : KeyEvent(key_code), m_repeat(repeat) {}

EventType KeyPressedEvent::type() const {
  return KEY_PRESSED;
}

bool KeyPressedEvent::repeat() const {
  return m_repeat;
}

}  // namespace event
}  // namespace creative
