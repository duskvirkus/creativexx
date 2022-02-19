#ifndef CREATIVEXX_MOUSESCROLLEDEVENT_H
#define CREATIVEXX_MOUSESCROLLEDEVENT_H

#include "Event.hxx"

namespace creative {
namespace event {

class MouseScrolledEvent : public Event {
 public:
  MouseScrolledEvent(float x_offset, float y_offset);

  MouseScrolledEvent(const MouseScrolledEvent&) = default;

  MouseScrolledEvent(const MouseScrolledEvent&&) = delete;

  MouseScrolledEvent operator=(const MouseScrolledEvent&) = delete;

  MouseScrolledEvent operator=(const MouseScrolledEvent&&) = delete;

  ~MouseScrolledEvent() override = default;

  [[nodiscard]] EventType type() const override;

  [[nodiscard]] float x_offset() const;

  [[nodiscard]] float y_offset() const;

 private:
  float m_x_offset;
  float m_y_offset;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_MOUSESCROLLEDEVENT_H
