#ifndef SPINWHEEL
#define SPINWHEEL

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/WheelSpinnerSubsystem.h"

class SpinWheel : public frc2::CommandHelper<frc2::CommandBase, SpinWheel>{
    public:
        SpinWheel(WheelSpinnerSubsystem* sub, double pow);
        void Execute() override;
        bool IsFinished() override;
        void Stop();
    private:
        WheelSpinnerSubsystem* m_sub;
        double m_pow;
        bool finished;
};

#endif