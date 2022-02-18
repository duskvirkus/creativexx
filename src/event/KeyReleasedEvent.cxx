#include "KeyReleasedEvent.hxx"

namespace creative {
namespace event {

KeyReleasedEvent::KeyReleasedEvent(unsigned int key_code)
    : KeyEvent(key_code) {}

EventType KeyReleasedEvent::type() const {
  return KEY_RELEASED;
}

}  // namespace event
}  // namespace creative
