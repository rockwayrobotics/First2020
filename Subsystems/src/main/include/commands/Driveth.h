#pragma once


#include "subsystems/DrivebaseSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Command.h>

class Driveth : public frc2::CommandHelper<frc2::CommandBase, Driveth>{
    public:
        Driveth(DrivebaseSubsystem* Drbase);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
};
