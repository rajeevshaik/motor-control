#ifndef MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_GPIO_H
#define MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_GPIO_H

namespace motorcontrol
{
/**
 * @brief an interface to motor gpio pins
 */
class MotorGpio
{
public:
    virtual ~MotorGpio() = default;
    /**
     * @brief calibrate the motor
     */
    virtual void write() const = 0;
}; // MotorGpio
}  // namespace motorcontrol

#endif  // MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_GPIO_H
