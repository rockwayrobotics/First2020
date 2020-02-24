#include "commands/ToggleHopper.h"
#include <iostream>

ToggleHopper::ToggleHopper(HopperSubsystem* hopper) {
    std::cout << "toggler created" << std::endl;
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