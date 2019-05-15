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

  digitalWrite(enablePin, enabled());
  analogWrite(pwmPin, driverPower);

  return true;
}

void BTS7960::enable() { setEnabled(true); }

void BTS7960::disable() { setEnabled(false); }

void BTS7960::setEnabled(bool status) {
  if (!initialized()) {
    return;
  }

  enabledFlag = status;
  digitalWrite(enablePin, status);
}

bool BTS7960::enabled() const { return enabledFlag; }

void BTS7960::setPower(unsigned power) {
  if (!initialized()) {
    return;
  }

  driverPower =
      power >= PWMResolution<unsigned>() ? PWMResolution<unsigned>() : power;
  analogWrite(pwmPin, driverPower);
}

unsigned BTS7960::power() const { return driverPower; }

void BTS7960::setCurrentSensorRatio(double resistorValue,
                                    double currentSenseValue) {
  currentSensorRatioMultiplier = currentSenseValue / resistorValue;
}

double BTS7960::currentSensorRatio() const {
  return currentSensorRatioMultiplier;
}

double BTS7960::current() const {
  double sensorReading{static_cast<double>(analogRead(currentSensorPin))};
  double sensorVoltage{VoltsPerADCUnit<double>() * sensorReading};
  return sensorVoltage * currentSensorRatio();
}