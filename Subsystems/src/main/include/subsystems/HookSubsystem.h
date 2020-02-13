#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMTalonSRX.h>
#include "RobotMap.h"

class HookSubsystem : public frc2::SubsystemBase {
    public:
        HookSubsystem();
        void Extend();
        void Retract();
    private:
        frc::PWMTalonSRX m_motor {RobotMap::Motors::WINCHMOTOR};
};