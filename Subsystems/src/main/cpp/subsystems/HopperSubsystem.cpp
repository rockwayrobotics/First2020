#include "subsystems/HopperSubsystem.h"
#include <frc2/command/CommandScheduler.h>
#include <iostream>

HopperSubsystem::HopperSubsystem() {
    Load();
    FlapIn();
    m_dumped = false;
    m_solenoid.ClearAllPCMStickyFaults();
}

void HopperSubsystem::Load(bool flapOut) {
    std::cout << "Retracting hopper solenoid" << std::endl;
    if (flapOut) {
        FlapOut();
    } else {
        FlapIn();
    }
    m_solenoid.Set(frc::DoubleSolenoid::Value::kForward);
    std::cout << "Loading: " << GetState() << std::endl;
}

void HopperSubsystem::Dump(bool flapOut) {
    std::cout << "Extending hopper solenoid" << std::endl;
    if (flapOut) {
        FlapOut();
    } else {
        FlapIn();
    }
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

void HopperSubsystem::FlapIn() {
    std::cout << "Moving flap in\n";
    m_flap.Set(frc::DoubleSolenoid::Value::kReverse);
}

void HopperSubsystem::FlapOut() {
    std::cout << "Moving flap out\n";
    m_flap.Set(frc::DoubleSolenoid::Value::kForward);
}

frc::DoubleSolenoid::Value HopperSubsystem::GetState() {
    return m_solenoid.Get();
}