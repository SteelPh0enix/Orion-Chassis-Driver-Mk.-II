#include "BTS7960.hpp"

#include <Arduino.h>

BTS7960::BTS7960(uint8_t pwmPin, uint8_t enablePin, uint8_t currentSensorPin) {
  setPins(pwmPin, enablePin, currentSensorPin);
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

  return true;
}