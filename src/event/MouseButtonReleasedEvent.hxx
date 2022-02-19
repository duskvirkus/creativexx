#ifndef CREATIVEXX_MOUSEBUTTONRELEASEDEVENT_H
#define CREATIVEXX_MOUSEBUTTONRELEASEDEVENT_H

#include "MouseButtonEvent.hxx"

namespace creative {
namespace event {

class MouseButtonReleasedEvent : public MouseButtonEvent {
 public:
  explicit MouseButtonReleasedEvent(int button);

  MouseButtonReleasedEvent(const MouseButtonReleasedEvent&) = default;

  MouseButtonReleasedEvent(const MouseButtonReleasedEvent&&) = delete;

  MouseButtonReleasedEvent operator=(const MouseButtonReleasedEvent&) = delete;

  MouseButtonReleasedEvent operator=(const MouseButtonReleasedEvent&&) = delete;

  ~MouseButtonReleasedEvent() override = default;

  [[nodiscard]] EventType type() const override;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_MOUSEBUTTONRELEASEDEVENT_H
