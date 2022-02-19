#ifndef CREATIVEXX_WINDOWRESIZEDEVENT_H
#define CREATIVEXX_WINDOWRESIZEDEVENT_H

#include "Event.hxx"

namespace creative {
namespace event {

class WindowResizedEvent : public Event {
 public:
  WindowResizedEvent(unsigned int width, unsigned int height);

  WindowResizedEvent(const WindowResizedEvent&) = delete;

  WindowResizedEvent(const WindowResizedEvent&&) = delete;

  WindowResizedEvent operator=(const WindowResizedEvent&) = delete;

  WindowResizedEvent operator=(const WindowResizedEvent&&) = delete;

  ~WindowResizedEvent() override = default;

  EventType type() const override;

  unsigned int width() const;

  unsigned int height() const;

 private:
  unsigned int m_width;
  unsigned int m_height;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_WINDOWRESIZEDEVENT_H
