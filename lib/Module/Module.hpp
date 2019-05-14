#pragma once

/*
  Base class for every initializable module which needs physical pins, and
  initialization. Every class inheriting this interface should provide:
  * internalInitialize implementation, returning initialization result (true
    for success)
  * setPins function, setting arePinsSet flag to `true` when called (may do
    checks if needed)
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