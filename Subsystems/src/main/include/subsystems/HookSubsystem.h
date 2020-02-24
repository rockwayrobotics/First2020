#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMTalonSRX.h>
#include <frc/AnalogPotentiometer.h>
#include "RobotMap.h"

const double fullRange = 1;
const double offset = 0;

class HookSubsystem : public frc2::SubsystemBase {
    public:
        HookSubsystem();
        void Extend();
        void Retract();
        void Move(double pow);
        double GetHeight();
        void Periodic() override;
    private:
        frc::PWMTalonSRX m_motor {RobotMap::Motors::WINCHMOTOR};
        frc::AnalogPotentiometer m_pot {RobotMap::Analog::HOOKPOT, fullRange, offset};
        double m_pow;
};