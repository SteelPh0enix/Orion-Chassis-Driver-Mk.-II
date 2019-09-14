#pragma once
#include <stdint.h>
#include "../Module/Module.hpp"

class BTS7960 : public Module {
 public:
  enum class Direction { None, Forward, Backward };

  BTS7960() = default;
  BTS7960(uint8_t pwmAPin, uint8_t pwmBPin, uint8_t directionAPin,
          uint8_t directionBPin, uint8_t feedbackAPin, uint8_t feedbackBPin);

  void setPins(uint8_t pwmAPin, uint8_t pwmBPin, uint8_t directionAPin,
               uint8_t directionBPin, uint8_t feedbackAPin,
               uint8_t feedbackBPin);

  void setPower(int power);
  void setDirection(Direction direction);
  void stop();

  void powerStep();
  void setPowerStepAmount(int amount);

  int actualPower() const { return m_actualPower; }

 private:
  int calculateNextPowerStep();
  void setPowerInstant(int power);
  virtual bool internalInitialize();

  uint8_t m_pwmAPin{};
  uint8_t m_pwmBPin{};
  uint8_t m_directionAPin{};
  uint8_t m_directionBPin{};
  uint8_t m_feedbackAPin{};
  uint8_t m_feedbackBPin{};

  int m_targetPower{};
  int m_actualPower{};
  unsigned m_powerStep{5};
  Direction m_direction{Direction::None};
};