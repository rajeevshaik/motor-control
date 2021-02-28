#ifndef MOTOR_CONTROL_SRC_SERVO_MOTOR_H
#define MOTOR_CONTROL_SRC_SERVO_MOTOR_H

#include <atomic>

#include "motor-control/calibrate_motor.h"
#include "motor-control/motor.h"
#include "motor-control/motor_gpio.h"

namespace motorcontrol
{
/**
 * @brief Motor interface to control different motors
 */
class Servo : public Motor
{
public:
    Servo(const CalibrateMotor& calibrator, const MotorGpio& gpio);
    ~Servo() override = default;
    void setDurationWidth(std::chrono::milliseconds duration) override;
    void setPeriod(AnyPeriodSize size) override;
    void calibrate() override;
    void start(Direction direction) override;
    void stop() override;

private:
    const CalibrateMotor& _calibrator;
    const MotorGpio& _gpio;
    std::chrono::milliseconds _duration{};
    std::chrono::milliseconds _periodSize{};
    std::atomic<bool> _isStarted{};
};  // Servo
}  // namespace motorcontrol
#endif // MOTOR_CONTROL_SRC_SERVO_MOTOR_H
