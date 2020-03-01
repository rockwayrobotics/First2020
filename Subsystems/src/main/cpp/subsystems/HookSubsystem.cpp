#include "subsystems/HookSubsystem.h"

HookSubsystem::HookSubsystem() {
    m_pow = 0;
    m_priority = 0;
}

void HookSubsystem::Extend(int priority) {
    if (priority >= m_priority) {
        m_pow = 1;
        priority = m_priority;
    }
}

void HookSubsystem::Retract(int priority) {
    if (priority >= m_priority) {
        m_pow = -1;
        priority = m_priority;
    }
}

void HookSubsystem::Move(double pow, int priority) {
    if (priority >= m_priority) {
        m_pow = pow;
        priority = m_priority;
    }
}

double HookSubsystem::GetHeight() {
    return m_pot.Get();
}

void HookSubsystem::Periodic() {
    m_motor.Set(m_pow);
    m_pow = 0;
    m_priority = 0;
}