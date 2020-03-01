#ifndef WHEELSPINNERSUBSYSTEM
#define WHEELSPINNERSUBSYSTEM

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Command.h>

#include <ctre/Phoenix.h>
#include "RobotMap.h"


class WheelSpinnerSubsystem : public frc2::SubsystemBase {
    public:
        WheelSpinnerSubsystem();
        void Spin(double spinPow);
        void Periodic() override;
    private:
        WPI_TalonSRX m_motor {RobotMap::CAN::WHEELMOTOR};
        double m_spinPow;
};

#endif