#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ColourSensorSubsystem.h"

class UpdateColourSensor : public frc2::CommandHelper<frc2::CommandBase, UpdateColourSensor> {
    public:
        explicit UpdateColourSensor(ColourSensorSubsystem* colourSensor);
        void Execute() override;
        bool IsFinished() override;
    private:
        ColourSensorSubsystem* m_colourSensor;
};