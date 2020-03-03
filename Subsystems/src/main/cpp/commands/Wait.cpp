#include "commands/Wait.h"
#include <iostream>

Wait::Wait(int cycles) {
    m_target = cycles;
}

void Wait::Initialize() {
    m_count = 0;
    std::cout << "Waiting " << m_target << " cycles...\n";
}

void Wait::Execute() {
    m_count++;
}

bool Wait::IsFinished() {
    return m_count >= m_target;
}

void Wait::End(bool interrupted) {
    if (interrupted) {
        std::cout << "Wait interrupted at " << m_count << std::endl;
    }
    else {
        std::cout << "Done\n";
    }
}