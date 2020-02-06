#ifndef SPINWHEELTOCOLOUR
#define SPINWHEELTOCOLOUR

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/WheelSpinnerSubsystem.h"
#include "subsystems/ColourSensorSubsystem.h"
#include "RobotMap.h"

class SpinWheelToColour : public frc2::CommandHelper<frc2::CommandBase, SpinWheelToColour>{
    public:
        SpinWheelToColour(WheelSpinnerSubsystem* wheel, ColourSensorSubsystem* colour, RobotMap::Colour target);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
        void Stop();
    private:
        WheelSpinnerSubsystem* m_wheel;
        ColourSensorSubsystem* m_colour;
        RobotMap::Colour m_target;
        bool m_finished;
};

#endif