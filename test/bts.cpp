#include <Arduino.h>
#include <BTS7960.hpp>
#include <Settings.hpp>

constexpr uint8_t BTSPWMPin{};
constexpr uint8_t BTSEnablePin{};
constexpr uint8_t BTSSensorPin{};

BTS7960 bts(BTSPWMPin, BTSEnablePin, BTSSensorPin);

void BTSTestFastPowerChange(BTS7960& bts, unsigned maxPower, unsigned stepCount,
                            unsigned sleepTime) {
  unsigned powerPerStep{maxPower / stepCount};
  bts.setPower(0);
  bts.enable();

  for (unsigned step{1}; step <= stepCount; step++) {
    char messageBuffer[64]{};
    sprintf(messageBuffer, "Powering up, step #%d of %d. Power: %d", step,
            stepCount, powerPerStep * step);
    Serial.println(messageBuffer);

    bts.setPower(powerPerStep * step);
    delay(sleepTime);
  }

  for (unsigned step{1}; step <= stepCount; step++) {
    char messageBuffer[64]{};
    sprintf(messageBuffer, "Powering down, step #%d of %d. Power: %d", step,
            stepCount, powerPerStep * step);
    Serial.println(messageBuffer);

    bts.setPower(powerPerStep * step);
    delay(sleepTime);
  }

  Serial.println("Test finished, shutting BTS down");
  bts.setPower(0);
  bts.disable();
}

void BTSTestSlowPowerChange(BTS7960& bts, unsigned maxPower,
                            unsigned stepIncrease, unsigned stepTime) {
  bts.setPower(0);
  bts.enable();

  unsigned stepCount = maxPower / stepIncrease;

  char messageBuffer[100]{};
  sprintf(messageBuffer,
          "Increasing power by %d every %dms for %dms to reach %d power ratio",
          stepIncrease, stepTime, stepCount * stepTime, maxPower);
  Serial.println(messageBuffer);

  for (unsigned step{0}; step < stepCount; step++) {
    bts.setPower(bts.power() + stepIncrease);
    delay(stepTime);
  }

  Serial.println("Decreasing power the same way...");
  for (unsigned step{0}; step < stepCount; step++) {
    bts.setPower(bts.power() - stepIncrease);
    delay(stepTime);
  }

  bts.setPower(0);
  bts.disable();
}

void setup() {
  Serial.begin(Settings::SerialBaudRate<unsigned long>());
  Serial.print("BTS initialization: ");
  Serial.println(bts.initialize() ? "Successfull" : "Failed");

  // Put tests here
}

void loop() {}