#include "subsystems/WheelSpinnerSubsystem.h"

WheelSpinnerSubsystem::WheelSpinnerSubsystem() {
}

void WheelSpinnerSubsystem::Spin(double spinPow) {
    m_motor.Set(spinPow);
}

void WheelSpinnerSubsystem::Stop() {
    currentCommand->Cancel();
}
