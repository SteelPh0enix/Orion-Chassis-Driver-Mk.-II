#include <Arduino.h>
#include <stdint.h>

namespace Pinout {
using PinT = uint8_t;
namespace WheelLF {
constexpr PinT PWMA{2};
constexpr PinT PWMB{3};
constexpr PinT DirectionB{22};
constexpr PinT DirectionA{23};
constexpr PinT FeedbackA{A0};
constexpr PinT FeedbackB{A1};
}  // namespace WheelLF
namespace WheelRF {
constexpr PinT PWMA{6};
constexpr PinT PWMB{7};
constexpr PinT DirectionB{26};
constexpr PinT DirectionA{27};
constexpr PinT FeedbackA{A4};
constexpr PinT FeedbackB{A5};
}  // namespace WheelRF
namespace WheelLB {
constexpr PinT PWMA{4};
constexpr PinT PWMB{5};
constexpr PinT DirectionB{24};
constexpr PinT DirectionA{25};
constexpr PinT FeedbackA{A2};
constexpr PinT FeedbackB{A3};
}  // namespace WheelLB
namespace WheelRB {
constexpr PinT PWMA{8};
constexpr PinT PWMB{9};
constexpr PinT DirectionB{28};
constexpr PinT DirectionA{29};
constexpr PinT FeedbackA{A6};
constexpr PinT FeedbackB{A7};
}  // namespace WheelRB
}  // namespace Pinout