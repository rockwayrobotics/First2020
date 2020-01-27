#pragma once

#include <frc/I2C.h>

const struct {
    // Motors
    const int LEFTMOTOR1 = 2;
    const int LEFTMOTOR2 = 1;
    const int RIGHTMOTOR1 = 3;
    const int RIGHTMOTOR2 = 4;
    const int WINCHMOTOR = 5;

    // Controllers
    const int XBOX = 1;
    const int FLIGHT = 0;

    // Colour Sensor port
    const frc::I2C::Port COLOURSENSOR = frc::I2C::Port::kOnboard;
} RobotMap;