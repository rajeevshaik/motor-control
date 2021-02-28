#ifndef MOTOR_CONTROL_SRC_DEFAULT_MOTOR_GPIO_H
#define MOTOR_CONTROL_SRC_DEFAULT_MOTOR_GPIO_H

#include "motor-control/motor_gpio.h"

namespace motorcontrol
{
class DefaultGpio : public MotorGpio
{
public:
    DefaultGpio() = default;
    ~DefaultGpio() override = default;
    void write() const override;
}; // DefaultGpio
}  // namespace motorcontrol

#endif  // MOTOR_CONTROL_SRC_DEFAULT_MOTOR_GPIO_H
