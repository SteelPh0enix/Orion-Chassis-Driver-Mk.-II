#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <BTS7960.hpp>
#include <Pinout.hpp>
#include <Settings.hpp>
#include <driving_algorithm.hpp>

BTS7960 wheelLF;
BTS7960 wheelRF;
BTS7960 wheelLB;
BTS7960 wheelRB;

char jsonBuffer[Settings::JsonBufferSize]{};
ArduinoJson::StaticJsonDocument<Settings::JsonBufferSize> jsonDoc{};

DefaultDriveAlgorithm algo;

void setup() {
  Serial.begin(Settings::SerialBaudRate);

  wheelLF.setPins(Pinout::WheelLF::PWMF, Pinout::WheelLF::PWMB,
                  Pinout::WheelLF::DirectionF, Pinout::WheelLF::DirectionB,
                  Pinout::WheelLF::FeedbackF, Pinout::WheelLF::FeedbackB);
  wheelRF.setPins(Pinout::WheelRF::PWMF, Pinout::WheelRF::PWMB,
                  Pinout::WheelRF::DirectionF, Pinout::WheelRF::DirectionB,
                  Pinout::WheelRF::FeedbackF, Pinout::WheelRF::FeedbackB);
  wheelLB.setPins(Pinout::WheelLB::PWMF, Pinout::WheelLB::PWMB,
                  Pinout::WheelLB::DirectionF, Pinout::WheelLB::DirectionB,
                  Pinout::WheelLB::FeedbackF, Pinout::WheelLB::FeedbackB);
  wheelRB.setPins(Pinout::WheelRB::PWMF, Pinout::WheelRB::PWMB,
                  Pinout::WheelRB::DirectionF, Pinout::WheelRB::DirectionB,
                  Pinout::WheelRB::FeedbackF, Pinout::WheelRB::FeedbackB);

  wheelLF.initialize();
  wheelRF.initialize();
  wheelLB.initialize();
  wheelRB.initialize();
}

void loop() {
  if (Serial.available()) {
    Serial.readBytesUntil('\n', jsonBuffer, Settings::JsonBufferSize);
    jsonDoc.clear();
    auto deserializationResult =
        ArduinoJson::deserializeJson(jsonDoc, jsonBuffer);
    if (deserializationResult == ArduinoJson::DeserializationError::Ok) {
      auto wheelInput = algo.translate(jsonDoc["id"]["ROT"], jsonDoc["id"]["PWM"]);
      wheelLF.setPower(wheelInput.left_speed);
      wheelLB.setPower(wheelInput.left_speed);
      wheelRB.setPower(wheelInput.right_speed);
      wheelRF.setPower(wheelInput.right_speed);
      jsonDoc.clear();
      jsonDoc["ErrorCode"] = 0;
      jsonDoc["ErrorDescription"] = "OK";
      jsonDoc["LF"] = wheelLF.power();
      jsonDoc["RF"] = wheelRF.power();
      jsonDoc["LB"] = wheelLB.power();
      jsonDoc["RB"] = wheelRB.power();
    } else {
      wheelLF.stop();
      wheelRF.stop();
      wheelLB.stop();
      wheelRB.stop();
      jsonDoc.clear();
      jsonDoc["ErrorCode"] = deserializationResult.code();
      jsonDoc["ErrorDescription"] = deserializationResult.c_str();
    }
    ArduinoJson::serializeJson(jsonDoc, Serial);
    Serial.println();
  }
}