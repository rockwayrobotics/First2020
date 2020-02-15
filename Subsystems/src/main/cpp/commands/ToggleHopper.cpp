#include "commands/ToggleHopper.h"
#include <iostream>

ToggleHopper::ToggleHopper(HopperSubsystem* hopper) {
    std::cout << "toggler created" << std::endl;
    m_hopper = hopper;
    m_dumped = false;
    m_finished = false;
}

void ToggleHopper::Initialize() {
    m_finished = false;
    std::cout << "triggered toggle" << std::endl;
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