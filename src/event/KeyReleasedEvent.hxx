#ifndef CREATIVEXX_KEYRELEASEDEVENT_H
#define CREATIVEXX_KEYRELEASEDEVENT_H

#include "KeyEvent.hxx"

namespace creative {
namespace event {

class KeyReleasedEvent : public KeyEvent {
 public:
  explicit KeyReleasedEvent(unsigned int key_code);

  KeyReleasedEvent(const KeyReleasedEvent&) = default;

  KeyReleasedEvent(const KeyReleasedEvent&&) = delete;

  KeyReleasedEvent operator=(const KeyReleasedEvent&) = delete;

  KeyReleasedEvent operator=(const KeyReleasedEvent&&) = delete;

  ~KeyReleasedEvent() override = default;

  EventType type() const override;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_KEYRELEASEDEVENT_H
