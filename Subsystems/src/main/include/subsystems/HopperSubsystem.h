#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class HopperSubsystem : public frc2::SubsystemBase {
    public:
        HopperSubsystem();
        void Dump();
        void Load();
        void Toggle();
        void Off();
        frc::DoubleSolenoid::Value GetState();
    private:
        frc::DoubleSolenoid m_solenoid {
            RobotMap::Pneumatics::HOPPERFORWARD,
            RobotMap::Pneumatics::HOPPERREVERSE
        };
        bool m_dumped;
};