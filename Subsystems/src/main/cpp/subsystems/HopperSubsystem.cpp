#include "subsystems/HopperSubsystem.h"

HopperSubsystem::HopperSubsystem() {
}

void HopperSubsystem::Load() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void HopperSubsystem::Dump() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

frc::DoubleSolenoid::Value HopperSubsystem::GetState() {
    return m_solenoid.Get();
}