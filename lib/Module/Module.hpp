#pragma once

/*
  Base class for every initializable module which needs physical pins, and
  initialization. Every class inheriting this interface should provide
    * internalInitialize implementation
    * setPins function
*/

class Module {
 public:
  virtual ~Module() = default;

  bool initialize() {
    if (!pinsSet()) {
      return false;
    }

    return internalInitialize();
  }

  bool initialized() const { return isInitialized; }
  bool pinsSet() const { return arePinsSet; }

 protected:
  bool arePinsSet{false};
  bool isInitialized{false};

  virtual bool internalInitialize() = 0;
};