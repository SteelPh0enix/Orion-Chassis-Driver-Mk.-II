#include <Arduino.h>
#include <BTS7960.hpp>
#include <Pinout.hpp>
#include <Settings.hpp>

namespace WheelPinout = Pinout::WheelRF;
BTS7960 driver(WheelPinout::PWMA, WheelPinout::PWMB, WheelPinout::DirectionA, WheelPinout::DirectionB, WheelPinout::FeedbackA, WheelPinout::FeedbackB);

void setup() {
  Serial.begin(Settings::SerialBaudRate);
  driver.initialize();

  Serial.print("Pins set? ");
  Serial.println(driver.pinsSet());
  Serial.print("Initialized? ");
  Serial.println(driver.initialized());
}

void testDriveForward(unsigned long delayTime) {
  Serial.println("Testing driving forward...");
  for(int i = 0; i < driver.PWMResolution(); i += 10) {
    driver.setPower(i);
    delay(delayTime);
  }

  for(int i = driver.PWMResolution(); i >= 0; i -= 10) {
    driver.setPower(i);
    delay(delayTime);
  }

  driver.setPower(0);
  Serial.println("Test finished!");
}

void loop() {
  testDriveForward(100);
  while(true) {
    delay(100);
  }
}