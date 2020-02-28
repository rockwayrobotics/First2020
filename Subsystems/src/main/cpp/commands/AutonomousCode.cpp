
#include "commands/AutonomousCode.h"
#include "frc2/command/SequentialCommandGroup.h"

Autonomous::Autonomous(DrivebaseSubsystem* Drbase) {
    AddCommands(
        Driveth {Drbase, 0.5, 0, 500}, 
        Driveth {Drbase, 1, 0, 50},
        Chargeth {Drbase, 0.5 , 0.001} //The chargeth command activated in autonomous which as of now in writing I dont know if it works
    //At the curretn moment the chargeth goes forever which needs to be fixed
    );
}
