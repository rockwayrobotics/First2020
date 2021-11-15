#pragma once


#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Driveth : public frc2::CommandHelper<frc2::CommandBase, Driveth>{
    public:
        Driveth(DrivebaseSubsystem* Drbase, double y, double x, int time);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
        double m_y, m_x;
        int m_time;
};
