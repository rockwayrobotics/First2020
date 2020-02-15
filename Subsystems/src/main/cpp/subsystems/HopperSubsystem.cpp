#include "subsystems/HopperSubsystem.h"
#include <iostream>

HopperSubsystem::HopperSubsystem() {
}

void HopperSubsystem::Load() {
    std::cout << "Retracting hopper solenoid" << std::endl; 
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void HopperSubsystem::Dump() {
    std::cout << "Extending hopper solenoid" << std::endl;
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

frc::DoubleSolenoid::Value HopperSubsystem::GetState() {
    return m_solenoid.Get();
}