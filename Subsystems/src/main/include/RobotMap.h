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
        WINCHMOTOR = 6,
        WHEELMOTOR = 5
    };
    enum Controllers { 
        // Controller ports
        XBOX = 0,
        FLIGHT = 1
    };
    const frc::I2C::Port COLOURSENSOR = frc::I2C::Port::kOnboard;
    enum Colour {
        // Colours used for the colour sensor and wheel spinner
        NONE = 0,
        RED = 1,
        BLUE = 2,
        GREEN = 3,
        YELLOW = 4
    };
}

#endif