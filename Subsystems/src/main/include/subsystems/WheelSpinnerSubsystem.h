#ifndef WHEELSPINNERSUBSYSTEM
#define WHEELSPINNERSUBSYSTEM

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Command.h>

#include <frc/PWMTalonSRX.h>
#include "RobotMap.h"


class WheelSpinnerSubsystem : public frc2::SubsystemBase {
    public:
        WheelSpinnerSubsystem();
        void Spin(double spinPow);
        void Periodic() override;
    private:
        frc::PWMTalonSRX m_motor {RobotMap::Motors::WHEELMOTOR};
        double m_spinPow;
};

#endif