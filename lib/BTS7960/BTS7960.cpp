#include "BTS7960.hpp"
#include <Arduino.h>

BTS7960::BTS7960(uint8_t pwmAPin, uint8_t pwmBPin, uint8_t directionAPin,
                 uint8_t directionBPin, uint8_t feedbackAPin,
                 uint8_t feedbackBPin) {
  setPins(pwmAPin, pwmBPin, directionAPin, directionBPin, feedbackAPin,
          feedbackBPin);
}
void BTS7960::setPins(uint8_t pwmAPin, uint8_t pwmBPin, uint8_t directionAPin,
                      uint8_t directionBPin, uint8_t feedbackAPin,
                      uint8_t feedbackBPin) {
  m_directionAPin = directionAPin;
  m_directionBPin = directionBPin;
  m_pwmAPin = pwmAPin;
  m_pwmBPin = pwmBPin;
  m_feedbackAPin = feedbackAPin;
  m_feedbackBPin = feedbackBPin;
  pinsHasBeenSet();
}

bool BTS7960::internalInitialize() {
  pinMode(m_feedbackAPin, INPUT);
  pinMode(m_feedbackBPin, INPUT);
  pinMode(m_pwmAPin, OUTPUT);
  pinMode(m_pwmBPin, OUTPUT);
  pinMode(m_directionAPin, OUTPUT);
  pinMode(m_directionBPin, OUTPUT);
  return true;
}

void BTS7960::setDirection(BTS7960::Direction direction) {
  switch (direction) {
    case Direction::None:
      digitalWrite(m_directionAPin, LOW);
      digitalWrite(m_directionBPin, LOW);
      break;
    case Direction::Forward:
      digitalWrite(m_directionAPin, HIGH);
      digitalWrite(m_directionBPin, LOW);
      break;
    case Direction::Backward:
      digitalWrite(m_directionAPin, LOW);
      digitalWrite(m_directionBPin, HIGH);
      break;
  }
}

void BTS7960::stop() { setPower(0); }

void BTS7960::setPower(int power) {
  power = constrain(power, -PWMResolution(), PWMResolution());
  if (power > 0) {
    setDirection(Direction::Forward);
    analogWrite(m_pwmAPin, power);
    analogWrite(m_pwmBPin, 0);
  } else if (power == 0) {
    setDirection(Direction::None);
    analogWrite(m_pwmAPin, 0);
    analogWrite(m_pwmBPin, 0);
  } else {
    setDirection(Direction::Backward);
    analogWrite(m_pwmAPin, 0);
    analogWrite(m_pwmBPin, power * -1);
  }

  m_power = power;
}

int BTS7960::power() const { return m_power; }