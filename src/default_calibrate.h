#ifndef MOTOR_CONTROL_SRC_DEFAULT_CALIBRATE_H
#define MOTOR_CONTROL_SRC_DEFAULT_CALIBRATE_H

#include "motor-control/calibrate_motor.h"

namespace motorcontrol
{
class DefaultCalibrate : public CalibrateMotor
{
public:
    DefaultCalibrate() = default;
    ~DefaultCalibrate() override = default;
    void calibrate() const override;
}; // DefaultCalibrate
}  // namespace motorcontrol

#endif  // MOTOR_CONTROL_SRC_DEFAULT_CALIBRATE_H
