#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMTalonSRX.h>
#include "RobotMap.h"

class HookSubsystem : public frc2::SubsystemBase {
    public:
        HookSubsystem();
        void Extend();
        void Retract();
        void Move(double pow);
        void Periodic() override;
    private:
        frc::PWMTalonSRX m_motor {RobotMap::Motors::WINCHMOTOR};
        double m_pow;
};