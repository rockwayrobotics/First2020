#include "commands/AutonomousCode.h"
#include <frc2/command/SequentialCommandGroup.h>

#include "AutonomousConstants.h"

#include "commands/Driveth.h"
#include "commands/Chargeth.h"
#include "commands/Wait.h"
#include "commands/ToggleHopper.h"

Autonomous::Autonomous(DrivebaseSubsystem* Drbase, HopperSubsystem* hopper) {
    AddCommands(
        Wait {AutonomousConstants::InitialWait}, // This is the wait that is at the begining of autonomous
        Chargeth {Drbase, AutonomousConstants::ForwardSpeed, AutonomousConstants::ForwardDistance} //Goes forward for a distance
    );
    if (AutonomousConstants::Dump) {
        AddCommands(ToggleHopper {hopper});
    }
    AddCommands(
        Wait {AutonomousConstants::DumpWait}, //This should be the time it takes for the balls to roll out
        Chargeth {Drbase, -AutonomousConstants::BackwardsSpeed, AutonomousConstants::BackwardsDistance} //Goes backward for a distance
    );
}
