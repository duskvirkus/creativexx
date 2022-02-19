#ifndef CREATIVEXX_KEYPRESSEDEVENT_H
#define CREATIVEXX_KEYPRESSEDEVENT_H

#include "KeyEvent.hxx"

namespace creative {
namespace event {

class KeyPressedEvent : public KeyEvent {
 public:
  KeyPressedEvent(unsigned int key_code, bool repeat);

  KeyPressedEvent(const KeyPressedEvent&) = default;

  KeyPressedEvent(const KeyPressedEvent&&) = delete;

  KeyPressedEvent operator=(const KeyPressedEvent&) = delete;

  KeyPressedEvent operator=(const KeyPressedEvent&&) = delete;

  ~KeyPressedEvent() override = default;

  [[nodiscard]] EventType type() const override;

  [[nodiscard]] bool repeat() const;

 private:
  bool m_repeat;
};

}  // namespace event
}  // namespace creative

#endif  // CREATIVEXX_KEYPRESSEDEVENT_H
