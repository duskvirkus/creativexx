#ifndef CREATIVEXX_MOUSEMOVEDEVENT_H
#define CREATIVEXX_MOUSEMOVEDEVENT_H

#include "Event.hxx"

namespace creative {
namespace event {

class MouseMovedEvent : public Event {
 public:
  MouseMovedEvent(float x, float y);

  MouseMovedEvent(const MouseMovedEvent&) = default;

  MouseMovedEvent(const MouseMovedEvent&&) = delete;

  MouseMovedEvent operator=(const MouseMovedEvent&) = delete;

  MouseMovedEvent operator=(const MouseMovedEvent&&) = delete;

  ~MouseMovedEvent() override = default;

  EventType type() const override;

  float x() const;

  float y() const;

 private:
  float m_x;
  float m_y;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_MOUSEMOVEDEVENT_H
