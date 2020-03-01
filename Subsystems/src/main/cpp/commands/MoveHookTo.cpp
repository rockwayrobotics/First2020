#include "commands/MoveHookTo.h"

#include <cmath>
#include <iostream>

const double MARGIN = 0.1;

MoveHookTo::MoveHookTo(HookSubsystem* hook, double height) {
    AddRequirements({hook});
    m_hook = hook;
    m_target = height;
}

void MoveHookTo::Initialize() {
    std::cout << "Moving hook to " << m_target << std::endl;
    m_finished = false;
    if (m_hook->GetHeight() > m_target) {
        m_pow = -1;
    } else {
        m_pow = 1;
    }
    timeout = 0;
}

void MoveHookTo::Execute() {
    m_hook->Move(m_pow, 1);
    std::cout << "Moving hook. Reading: " << m_hook->GetHeight() << std::endl;
    timeout++;
    if (timeout > 100) {
        std::cout << "timed out\n";
    }
}

bool MoveHookTo::IsFinished() {
    return std::abs(m_hook->GetHeight() - m_target) > MARGIN || timeout > 100;
}