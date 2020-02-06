#include "commands/SpinWheel.h"

const double spinFactor = 0.2;

SpinWheel::SpinWheel(WheelSpinnerSubsystem* sub, double pow) {
    AddRequirements(sub);
    m_sub = sub;
    m_pow = pow * spinFactor;
}

void SpinWheel::Execute() {
    m_sub->Spin(m_pow);
}

bool SpinWheel::IsFinished() {
    return finished;
}

void SpinWheel::Stop() {
    finished = true;
}