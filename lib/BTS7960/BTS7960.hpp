#pragma once

#include <stdint.h>
#include "../Module/Module.hpp"

class BTS7960 : public Module {
 public:
  BTS7960() = default;
  BTS7960(uint8_t pwm, uint8_t enable, uint8_t currentSensor);

  void setPins(uint8_t pwm, uint8_t enable, uint8_t currentSensor);

 protected:
  virtual bool internalInitialize() override;

 private:
  uint8_t pwmPin{};
  uint8_t enablePin{};
  uint8_t currentSensorPin{};
};