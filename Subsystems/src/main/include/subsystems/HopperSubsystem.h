#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/DoubleSolenoid.h>

#include "RobotMap.h"

class HopperSubsystem : public frc2::SubsystemBase {
    public:
        HopperSubsystem();
        void Dump(bool flapOut = true);
        void Load(bool flapOut = true);
        void Toggle();
        void Off();
        void FlapIn();
        void FlapOut();
        frc::DoubleSolenoid::Value GetState();
    private:
        frc::DoubleSolenoid m_solenoid {
            RobotMap::Pneumatics::HOPPERFORWARD,
            RobotMap::Pneumatics::HOPPERREVERSE
        };
        frc::DoubleSolenoid m_flap {
            RobotMap::FLAPFORWARD,
            RobotMap::FLAPREVERSE
        };
        bool m_dumped;

};