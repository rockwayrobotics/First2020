#include "subsystems/WheelSpinnerSubsystem.h"

WheelSpinnerSubsystem::WheelSpinnerSubsystem() {
}

void WheelSpinnerSubsystem::Spin(double spinPow) {
    m_spinPow = spinPow;
}

void WheelSpinnerSubsystem::Periodic() {
    m_motor.Set(m_spinPow);
    m_spinPow = 0;
}
