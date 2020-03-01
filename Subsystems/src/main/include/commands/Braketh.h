#pragma once

#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

class Braketh : public frc2::CommandHelper<frc2::CommandBase, Braketh>{
    public:
        Braketh(DrivebaseSubsystem* Drbase, double braking_speed);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        double m_braking_speed;
        double m_speed;
        double m_current_encoder_value;
        double m_last_encoder_value;
        bool finished;
};