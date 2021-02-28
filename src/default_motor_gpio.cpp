#include "default_motor_gpio.h"

#include <iostream>

namespace motorcontrol
{
void DefaultGpio::write() const 
{
    std::cout << "writing to gpio pins" << std::endl;
}
} // motorcontrol
