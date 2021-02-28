#include "servo_motor.h"

#include "mock_calibrate_motor.h"
#include "mock_motor_gpio.h"

using namespace testing;

class SeroMotorTest : public Test
{
protected:
    void SetUp() override
    {
        _servo = std::make_unique<motorcontrol::Servo>(_calibrator, _gpio);
    }

    std::unique_ptr<motorcontrol::Servo> _servo;
    MockGpio _gpio;
    MockCalibrate _calibrator;
};

TEST_F(SeroMotorTest, when_calibrate_called_on_servo_should_call_mock_calibrate)
{
    EXPECT_CALL(_calibrator, calibrate());
    _servo->calibrate();
}

TEST_F(SeroMotorTest, when_servo_start_should_call_write_to_gpio)
{
    EXPECT_CALL(_gpio, write());
    _servo->start(motorcontrol::Motor::Direction::Clockwise);
}

TEST_F(SeroMotorTest, when_servo_start_called_twice_should_call_write_to_gpio_only_once)
{
    EXPECT_CALL(_gpio, write());
    _servo->start(motorcontrol::Motor::Direction::Clockwise);
    _servo->start(motorcontrol::Motor::Direction::Clockwise);
}

TEST_F(SeroMotorTest, when_servo_start_stop_start__should_call_write_to_gpio_twice)
{
    EXPECT_CALL(_gpio, write()).Times(2);
    _servo->start(motorcontrol::Motor::Direction::Clockwise);
    _servo->stop();
    _servo->start(motorcontrol::Motor::Direction::Clockwise);
}
