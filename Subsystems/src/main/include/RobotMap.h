#ifndef ROBOTMAP
#define ROBOTMAP

#include <frc/I2C.h>

namespace RobotMap {
    enum Motors {
        // Motor ports
        LEFTMOTOR1 = 1,
        LEFTMOTOR2 = 2,
        RIGHTMOTOR1 = 3,
        RIGHTMOTOR2 = 4,
        WINCHMOTOR = 5
    };
    enum Controllers { 
        // Controller ports
        XBOX = 0,
        FLIGHT = 1
    };
    const frc::I2C::Port COLOURSENSOR = frc::I2C::Port::kOnboard;
}

#endif