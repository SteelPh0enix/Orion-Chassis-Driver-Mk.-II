#include <Arduino.h>
#include <stdint.h>

namespace Pinout {
using PinT = uint8_t;
namespace WheelLF {
constexpr PinT PWMB{3};
constexpr PinT PWMF{2};
constexpr PinT DirectionF{23};
constexpr PinT DirectionB{22};
constexpr PinT FeedbackF{A0};
constexpr PinT FeedbackB{A1};
}  // namespace WheelLF
namespace WheelRF {
constexpr PinT PWMF{6};
constexpr PinT PWMB{7};
constexpr PinT DirectionF{27};
constexpr PinT DirectionB{26};
constexpr PinT FeedbackF{A5};
constexpr PinT FeedbackB{A4};
}  // namespace WheelRF
namespace WheelLB {
constexpr PinT PWMB{4};
constexpr PinT PWMF{5};
constexpr PinT DirectionF{25};
constexpr PinT DirectionB{24};
constexpr PinT FeedbackF{A2};
constexpr PinT FeedbackB{A3};
}  // namespace WheelLB
namespace WheelRB {
constexpr PinT PWMF{8};
constexpr PinT PWMB{9};
constexpr PinT DirectionF{29};
constexpr PinT DirectionB{28};
constexpr PinT FeedbackF{A6};
constexpr PinT FeedbackB{A7};
}  // namespace WheelRB
}  // namespace Pinout