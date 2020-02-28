#include "commands/Wait.h"

Wait::Wait(int cycles) {
    m_target = cycles;
}

void Wait::Initialize() {
    m_count = 0;
}

void Wait::Execute() {
    m_count++;
}

bool Wait::IsFinished() {
    return m_count == m_target;
}