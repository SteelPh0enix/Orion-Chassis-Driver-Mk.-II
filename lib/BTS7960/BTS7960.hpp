#pragma once

#include <stdint.h>
#include "../Module/Module.hpp"

class BTS7960 : public Module {
 public:
  BTS7960() = default;
  BTS7960(uint8_t pwmPin, uint8_t enablePin, uint8_t currentSensorPin);

  void setPins(uint8_t pwm, uint8_t enable, uint8_t currentSensor);

  void enable();
  void disable();
  void setEnabled(bool enabled);
  bool enabled() const;

  // Sets power in range of <0, 255> (analogWrite resolution). Constrains
  // values greater than 255.
  void setPower(unsigned power);
  unsigned power() const;

  // This ratio is used to calculate current based on current sense pin voltage
  // The formula is Iload = Iratio * Vsensor, where
  // * Iload is calculated load current
  // * Iratio is calculated ratio, based on current sense resistor (Ris) value
  // and current sense ratio (typically 8500)
  // * Vsensor is voltage on current sense resistor
  // Formula for Iratio is currentSenseValue / resistorValue
  void setCurrentSensorRatio(double resistorValue = 1000.,
                             double currentSenseValue = 8500.);
  double currentSensorRatio() const;

  double current() const;

 protected:
  virtual bool internalInitialize() override;

 private:
  uint8_t pwmPin{};
  uint8_t enablePin{};
  uint8_t currentSensorPin{};

  bool enabledFlag{false};
  unsigned driverPower{0};
  double currentSensorRatioMultiplier{8.5};
};