#ifndef ROBOTMAP
#define ROBOTMAP

#include <frc/I2C.h>

namespace RobotMap {
    enum CAN {
        // CAN IDs
        LEFTMOTOR1 = 1,
        LEFTMOTOR2 = 2,
        RIGHTMOTOR1 = 3,
        RIGHTMOTOR2 = 4,
        WINCHMOTOR = 5,
        WHEELMOTOR = 6
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
    enum Pneumatics {
        // pneumatic ports on PCM
        HOPPERFORWARD = 1,
        HOPPERREVERSE = 0,
        FLAPFORWARD = 6,
        FLAPREVERSE = 7
    };
    enum Analog {
        // analog ports on roboRIO
        HOOKPOT = 0
    };
    enum DIO {
        DBENCODERL1 = 0,
        DBENCODERL2 = 1,
        DBENCODERR1 = 2,
        DBENCODERR2 = 3
    };
}

#endif