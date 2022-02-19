#ifndef CREATIVEXX_MOUSEBUTTONPRESSEDEVENT_H
#define CREATIVEXX_MOUSEBUTTONPRESSEDEVENT_H

#include "MouseButtonEvent.hxx"

namespace creative {
namespace event {

class MouseButtonPressedEvent : public MouseButtonEvent {
 public:
  explicit MouseButtonPressedEvent(int button);

  MouseButtonPressedEvent(const MouseButtonPressedEvent&) = default;

  MouseButtonPressedEvent(const MouseButtonPressedEvent&&) = delete;

  MouseButtonPressedEvent operator=(const MouseButtonPressedEvent&) = delete;

  MouseButtonPressedEvent operator=(const MouseButtonPressedEvent&&) = delete;

  ~MouseButtonPressedEvent() override = default;

  [[nodiscard]] EventType type() const override;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_MOUSEBUTTONPRESSEDEVENT_H
