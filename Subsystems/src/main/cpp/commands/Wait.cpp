#include "commands/Wait.h"
#include <iostream>

Wait::Wait(int cycles) {
    m_target = cycles;
}

void Wait::Initialize() {
    m_count = 0;
}

void Wait::Execute() {
    std::cout << "Waiting " << m_count << " of " << m_target << std::endl;
    m_count++;
}

bool Wait::IsFinished() {
    return m_count >= m_target;
}