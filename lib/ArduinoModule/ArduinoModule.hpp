#pragma once

/*
  Base class for every initializable module which needs physical Arduino pins.
  Every class inheriting this interface should provide
    * internalInitialize implementation
    * setPins function
*/

class ArduinoModule {
 public:
  virtual ~ArduinoModule() = default;

  bool initialize() {
    if (!pinsSet()) {
      return false;
    }

    return internalInitialize();
  }

  bool initialized() const { return this->isInitialized; }
  bool pinsSet() const { return this->arePinsSet; }

 protected:
  bool arePinsSet{false};
  bool isInitialized{false};

  virtual bool internalInitialize() = 0;
};