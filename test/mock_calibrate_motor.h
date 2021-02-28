#ifndef MOTOR_CONTROL_TEST_MOCK_CALIBRATE_MOTOR_H
#define MOTOR_CONTROL_TEST_MOCK_CALIBRATE_MOTOR_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "motor-control/calibrate_motor.h"

class MockCalibrate : public motorcontrol::CalibrateMotor
{
public:
    MOCK_METHOD(void, calibrate, (), (const, override));
};

#endif  // MOTOR_CONTROL_TEST_MOCK_CALIBRATE_MOTOR_H
