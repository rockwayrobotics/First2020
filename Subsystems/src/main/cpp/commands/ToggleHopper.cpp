#include "commands/ToggleHopper.h"

ToggleHopper::ToggleHopper(HopperSubsystem* hopper) {
    m_hopper = hopper;
}

void ToggleHopper::Initialize() {
    m_finished = false;
    m_hopper->Toggle();
    m_finished = true;
}

bool ToggleHopper::IsFinished() {
    return m_finished;
}