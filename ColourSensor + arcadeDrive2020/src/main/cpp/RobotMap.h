// Constants for parts on the robot (ports, buttons, etc) go here

#ifndef ROBOTMAP
#define ROBOTMAP

const struct {
    // Motors
    const int LEFTMOTOR1 = 2;
    const int LEFTMOTOR2 = 1;
    const int RIGHTMOTOR1 = 3;
    const int RIGHTMOTOR2 = 4;
    const int WHEELMOTOR = 5;

    // Controllers
    const int XBOX = 0;
    const int FLIGHT = 1;
} RobotMap;
#endif