#ifndef UPDATECOLOURSENSOR
#define UPDATECOLOURSENSOR

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ColourSensorSubsystem.h"

class UpdateColourSensor : public frc2::CommandHelper<frc2::CommandBase, UpdateColourSensor> {
    public:
        UpdateColourSensor(ColourSensorSubsystem* colourSensor);
        void Execute() override;
        bool IsFinished() override;
    private:
        ColourSensorSubsystem* m_colourSensor;
};

#endif