#pragma once

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DrivebaseSubsystem.h"
#include "commands/Driveth.h"
#include "commands/Chargeth.h"

class Autonomous : public frc2::CommandHelper<frc2::SequentialCommandGroup, Autonomous> {
    public:
        Autonomous(DrivebaseSubsystem* Drbase);
};