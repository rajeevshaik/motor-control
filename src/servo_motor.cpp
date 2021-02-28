#include "servo_motor.h"

namespace motorcontrol
{
Servo::Servo(const CalibrateMotor& calibrator, const MotorGpio& gpio) :
    _calibrator(calibrator),
    _gpio(gpio)
{

}

void Servo::setDurationWidth(std::chrono::milliseconds duration)
{
    _duration = duration;
}

void Servo::setPeriod(AnyPeriodSize size)
{
    const std::chrono::milliseconds *val = std::get_if<std::chrono::milliseconds>(&size);
    if (val) {
        _periodSize = *val;;
    }
}

void Servo::calibrate()
{
    _calibrator.calibrate();
}

void Servo::start(Direction direction)
{
    if (_isStarted) {
        return;
    }
    _isStarted = true;
    _gpio.write();
}

void Servo::stop()
{
    if (!_isStarted) {
        return;
    }
    _isStarted = false;
}
}  // namespace motorcontrol