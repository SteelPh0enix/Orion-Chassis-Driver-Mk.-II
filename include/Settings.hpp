#pragma once

namespace Settings {
template <typename T>
constexpr T SerialBaudRate() {
  return 115200.;
}

constexpr size_t JsonBufferSize{256};
}  // namespace Settings