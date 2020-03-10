#include "commands/AutonomousCode.h"
#include <frc2/command/SequentialCommandGroup.h>

#include "AutonomousConstants.h"

#include "commands/Driveth.h"
#include "commands/Chargeth.h"
#include "commands/Wait.h"
#include "commands/ToggleHopper.h"
#include "commands/Turn2.h"

Autonomous::Autonomous(DrivebaseSubsystem* Drbase, HopperSubsystem* hopper) {
    // AddCommands(
    //     ToggleHopper {hopper},
    //     Wait {AutonomousConstants::InitialWait},
    //     //Turn2 {Drbase, 0.3, 30},
    //     Driveth {Drbase, -0.5, 0, 100} // This is the wait that is at the begining of autonomous
    // );
    AddCommands(
        Wait {AutonomousConstants::InitialWait}, // This is the wait that is at the begining of autonomous
        Chargeth {
            Drbase,
            AutonomousConstants::ForwardSpeed,
            AutonomousConstants::ForwardDistance,
            AutonomousConstants::ForwardTimeout
        }, //Goes forward for a distance
        Wait {AutonomousConstants::PreDumpWait}
    );
    if (AutonomousConstants::Dump) {
        AddCommands(ToggleHopper {hopper});
    }
    AddCommands(
        Wait {AutonomousConstants::DumpWait}, //This should be the time it takes for the balls to roll out
        Chargeth {Drbase,
            -AutonomousConstants::BackwardsSpeed,
            AutonomousConstants::BackwardsDistance,
            AutonomousConstants::BackwardsTimeout
        } //Goes backward for a distance
    );
}
