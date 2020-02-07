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
        void Stop();
    private:
        frc::PWMTalonSRX m_motor {RobotMap::Ports::WHEELMOTOR};
        double m_spinPow;
        frc2::Command* currentCommand = nullptr;
};

#endif