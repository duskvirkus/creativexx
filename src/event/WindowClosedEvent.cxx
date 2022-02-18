#include "WindowClosedEvent.hxx"

namespace creative {
namespace event {

EventType WindowClosedEvent::type() const {
  return WINDOW_CLOSED;
}

}  // namespace event
}  // namespace creative
