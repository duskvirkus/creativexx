#include "Event.hxx"

namespace creative {
namespace event {

Event::Event() : m_handled(false) {}

bool Event::handled() const {
  return m_handled;
}

}  // namespace event
}  // namespace creative
