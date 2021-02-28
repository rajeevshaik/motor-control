#ifndef MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_H
#define MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_H

#include <chrono>
#include <variant>

namespace motorcontrol
{
/**
 * @brief Motor interface to control different motors
 */
class Motor
{
public:
    /*
     * @brief AnyPeriodSize datatype holds number of steps required for stepper motor
     *                      or period size of the servo motor pulse
     */
    using AnyPeriodSize = std::variant<int, std::chrono::milliseconds>;
    /*
     * @brief motor type
     */
    enum class Type
    {
        Servo,     //!< a Servo motor
        Stepper,   //!< a Stepper motor
        AC,        //!< a AC motor
        DC         //!< a DC motor
    };
    /*
     * @brief rotation direction
     */
    enum class Direction
    {
        Clockwise,        //!< rotate motor in clockwise direction
        CounterClockwise, //!< rotate motor in counter clockwise direction
    };

    virtual ~Motor() = default;
    /**
     * @brief Set duration of positive pulse driving the servo/ step duration for stepper etc.
     * @param duration duration of the pulse width in milliseconds.
     */
    virtual void setDurationWidth(std::chrono::milliseconds duration) = 0;
    /**
     * @brief Set period of the servo or number of steps for stepper motor
     * @param size of period of the pulses/steps in AnyPeriodSize.
     */
    virtual void setPeriod(AnyPeriodSize size) = 0;
    /**
     * @brief calibration motor.
     */
    virtual void calibrate() = 0;
    /**
     * @brief start motor
     */
    virtual void start(Direction direction) = 0;
    /**
     * @brief stop motor
     */
    virtual void stop() = 0;
};  // Motor
}  // namespace motorcontrol
#endif // MOTOR_CONTROL_INCLUDE_MOTOR_CONTROL_MOTOR_H
