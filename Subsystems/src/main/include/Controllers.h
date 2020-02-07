#pragma once

#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include "RobotMap.h"

namespace Controllers {
    const frc::XboxController xbox {RobotMap::Controllers::XBOX};
    const frc::Joystick flight {RobotMap::Controllers::FLIGHT};
}