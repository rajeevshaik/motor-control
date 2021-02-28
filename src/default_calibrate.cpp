#include "default_calibrate.h"

#include <iostream>

namespace motorcontrol
{
void DefaultCalibrate::calibrate() const 
{
    std::cout << "motor calibration done!" << std::endl; 
}
} // motorcontrol
