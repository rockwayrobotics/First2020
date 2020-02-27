#include "commands/Braketh.h"
//Learning how to comment is rally useful so if you are reading this i sugest learning
Braketh::Braketh(DrivebaseSubsystem* Brbase) {
    m_Brbase = Brbase;
}

void Braketh::Initialize() {
    finished = false;
}

void Braketh::Execute() {

}

bool Braketh::IsFinished() {
    return true;
}
