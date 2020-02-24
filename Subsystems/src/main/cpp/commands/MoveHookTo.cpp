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
    m_finished = false;
    if (m_hook->GetHeight() > m_target) {
        m_pow = -1;
    } else {
        m_pow = 1;
    }
}

void MoveHookTo::Execute() {
    //m_hook->Move(m_pow);
    std::cout << "Moving hook. Reading: " << m_hook->GetHeight() << std::endl;
}

bool MoveHookTo::IsFinished() {
    //return std::abs(m_hook->GetHeight() - m_target) > MARGIN;
    return false;
}