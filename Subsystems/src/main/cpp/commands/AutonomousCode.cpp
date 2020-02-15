#include "commands/AutonomousCode.h"
#include "commands/Driveth.h"

Autonomous::Autonomous(DrivebaseSubsystem* Drbase) {
    m_Drbase = Drbase;
}

void Autonomous::Initialize() {
    finished = false;
}

void Autonomous::Execute() {
    frc2::CommandScheduler::GetInstance().Schedule(new Driveth{m_Drbase});
    
}


bool Autonomous::IsFinished() {
    return finished;
}
