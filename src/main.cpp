#include <iostream>

#include "default_calibrate.h"
#include "default_motor_gpio.h"
#include "servo_motor.h"

int main() 
{
	motorcontrol::DefaultCalibrate calibrate;
	motorcontrol::DefaultGpio gpio;
	motorcontrol::Servo servo(calibrate, gpio);
	servo.start(motorcontrol::Motor::Direction::Clockwise);
	std::cout << "Hello World from Motor";
	servo.stop();
}
