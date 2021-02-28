#ifndef MOTOR_CONTROL_TEST_MOCK_MOTOR_GPIO_H
#define MOTOR_CONTROL_TEST_MOCK_MOTOR_GPIO_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "motor-control/motor_gpio.h"

class MockGpio : public motorcontrol::MotorGpio
{
public:
    MOCK_METHOD(void, write, (), (const, override));
};

#endif  // MOTOR_CONTROL_TEST_MOCK_MOTOR_GPIO_H
