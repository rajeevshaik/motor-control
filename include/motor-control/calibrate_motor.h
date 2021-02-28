#ifndef MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_CALIBRATE_MOTOR_H
#define MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_CALIBRATE_MOTOR_H

namespace motorcontrol
{
/**
 * @brief Calibrate to calibrate different types of motors
 */
class CalibrateMotor
{
public:
    virtual ~CalibrateMotor() = default;
    /**
     * @brief calibrate the motor
     */
    virtual void calibrate() const = 0;
}; // CalibrateMotor
}  // namespace motorcontrol

#endif  // MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_CALIBRATE_MOTOR_H
