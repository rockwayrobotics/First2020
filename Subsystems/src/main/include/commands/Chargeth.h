#pragma once

#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Chargeth : public frc2::CommandHelper<frc2::CommandBase, Chargeth>{
    public:
        Chargeth(DrivebaseSubsystem* Drbase, double speed, double distance_going, int timeout = -1);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
        double m_speed;
        double m_distance_going;
        double m_startingDistanceL;
        double m_startingDistanceR;
        double m_targetDistanceL;
        double m_targetDistanceR;
        double m_powL;
        double m_powR;
        int m_timeout;
        int m_backwards;
};