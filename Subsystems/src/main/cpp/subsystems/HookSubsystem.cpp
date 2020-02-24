#include "subsystems/HookSubsystem.h"

HookSubsystem::HookSubsystem() {
    m_pow = 0;
}

void HookSubsystem::Extend() {
    m_pow = 1;
}

void HookSubsystem::Retract() {
    m_pow = -1;
}

void HookSubsystem::Move(double pow) {
    m_pow = pow;
}

double HookSubsystem::GetHeight() {
    return m_pot.Get();
}

void HookSubsystem::Periodic() {
    m_motor.Set(m_pow);
    m_pow = 0;
}