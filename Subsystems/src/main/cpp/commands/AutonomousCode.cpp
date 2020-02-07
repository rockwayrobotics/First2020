#include "commands/AutonomousCode.h"

Autonomous::Autonomous(RobotContainer* cont) {
    m_cont = cont;
    m_cont->Drive(1,1);
}

void Autonomous::Initialize() {

}

void Autonomous::Execute() {}

bool Autonomous::IsFinished() {
    return finished;
}
//This should eventually lol on that with the yeet skeet cheat