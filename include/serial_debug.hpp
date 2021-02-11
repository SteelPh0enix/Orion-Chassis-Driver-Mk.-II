#pragma once
#include "Arduino.h"

#define DEBUG 

template<typename T = const char*>
void serial_debug(const char* label, T value = "") {
  String str = String(label);
  String tmp = String(value);
  str.concat(tmp.c_str());
  const char* message = str.c_str();
  Serial.println(message);
}