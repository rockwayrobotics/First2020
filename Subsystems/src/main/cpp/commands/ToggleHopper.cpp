#include "commands/ToggleHopper.h"

ToggleHopper::ToggleHopper(HopperSubsystem* hopper) {
    m_hopper = hopper;
    m_dumped = (m_hopper->GetState() == frc::DoubleSolenoid::Value::kForward);
}

void ToggleHopper::Initialize() {
    if (m_dumped){
        m_hopper->Load();
    } else {
        m_hopper->Dump();
    }
    m_finished = true;
}

bool ToggleHopper::IsFinished() {
    return m_dumped;
}