#ifndef CREATIVEXX_EVENT_H
#define CREATIVEXX_EVENT_H

#include "EventType.hxx"

namespace creative {
namespace event {
class Event {
 public:
  virtual EventType type() const = 0;

 protected:
  Event();

  virtual ~Event() = default;

  [[nodiscard]] bool handled() const;

 private:
  bool m_handled;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_EVENT_H
