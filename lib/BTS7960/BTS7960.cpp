#include "BTS7960.hpp"

#include <Arduino.h>

BTS7960::BTS7960(uint8_t pwm, uint8_t enable, uint8_t currentSensor) {
  setPins(pwm, enable, currentSensor);
}

void BTS7960::setPins(uint8_t pwm, uint8_t enable, uint8_t currentSensor) {
  pwmPin = pwm;
  enablePin = enable;
  currentSensorPin = currentSensor;

  arePinsSet = true;
}

bool BTS7960::internalInitialize() {
  pinMode(pwmPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(currentSensorPin, INPUT);

  digitalWrite(enablePin, isEnabled());

  return true;
}

void BTS7960::enable() {
  isEnabledFlag = true;
  digitalWrite(enablePin, true);
}

void BTS7960::disable() {
  isEnabledFlag = false;
  digitalWrite(enablePin, false);
}

bool BTS7960::isEnabled() const { return isEnabledFlag; }