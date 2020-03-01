#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogPotentiometer.h>
#include "RobotMap.h"

const double fullRange = 1;
const double offset = 0;

class HookSubsystem : public frc2::SubsystemBase {
    public:
        HookSubsystem();
        void Extend(int priority);
        void Retract(int priority);
        void Move(double pow, int priority);
        double GetHeight();
        void Periodic() override;
    private:
        WPI_TalonSRX m_motor {RobotMap::CAN::WINCHMOTOR};
        frc::AnalogPotentiometer m_pot {RobotMap::Analog::HOOKPOT, fullRange, offset};
        double m_pow;
        int m_priority;
};