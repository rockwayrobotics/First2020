#pragma once

#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

class Chargeth : public frc2::CommandHelper<frc2::CommandBase, Chargeth>{
    public:
        Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going, int timeout = -1);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
        double m_y;
        double m_distance_going;
        double m_startingDistanceL;
        double m_startingDistanceR;
        double m_deltaL;
        double m_deltaR;
        double m_timeout;
        double m_cycles;

};