
#include "commands/AutonomousCode.h"
#include "frc2/command/SequentialCommandGroup.h"

Autonomous::Autonomous(DrivebaseSubsystem* Drbase) {
    AddCommands(
        Driveth {Drbase, 0.5, 0.5, 5}, 
        Driveth {Drbase, 0.5, 0.5, 50}
        
    );
}
