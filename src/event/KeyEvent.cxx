#include "KeyEvent.hxx"

namespace creative {
namespace event {

KeyEvent::KeyEvent(unsigned int key_code) : m_key_code(key_code) {}

unsigned int KeyEvent::key_code() const {
  return m_key_code;
}

}  // namespace event
}  // namespace creative
