#include "subsystems/HopperSubsystem.h"
#include <iostream>

HopperSubsystem::HopperSubsystem() {
    Load();
    m_dumped = false;
    m_solenoid.ClearAllPCMStickyFaults();
}

void HopperSubsystem::Load() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
    std::cout << "Loading: " << GetState() << std::endl;
}

void HopperSubsystem::Dump() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    std::cout << "Dumping: " << GetState() << std::endl;
}

void HopperSubsystem::Toggle() {
    if (m_dumped) {
        Load();
    } else {
        Dump();
    }
    m_dumped = !m_dumped;
    std::cout << "Toggled to " << GetState() << std::endl;
}

void HopperSubsystem::Off() {
    m_solenoid.Set(frc::DoubleSolenoid::Value::kOff);
    std::cout << "Turning off: " << GetState() << std::endl;
}

frc::DoubleSolenoid::Value HopperSubsystem::GetState() {
    return m_solenoid.Get();
}