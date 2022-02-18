#ifndef CREATIVEXX_WINDOWCLOSEDEVENT_H
#define CREATIVEXX_WINDOWCLOSEDEVENT_H

#include "Event.hxx"

namespace creative {
namespace event {

class WindowClosedEvent : public Event {
 public:
  WindowClosedEvent() = default;

  WindowClosedEvent(const WindowClosedEvent&) = delete;
  WindowClosedEvent(const WindowClosedEvent&&) = delete;

  WindowClosedEvent operator=(const WindowClosedEvent&) = delete;
  WindowClosedEvent operator=(const WindowClosedEvent&&) = delete;

  ~WindowClosedEvent() override = default;

  [[nodiscard]] EventType type() const override;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_WINDOWCLOSEDEVENT_H
