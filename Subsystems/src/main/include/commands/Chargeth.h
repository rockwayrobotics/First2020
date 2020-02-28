#pragma once

#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

class Chargeth : public frc2::CommandHelper<frc2::CommandBase, Chargeth>{
    public:
        Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
        double m_y;
        double m_distance_going;
        double m_distance_travelled;

};