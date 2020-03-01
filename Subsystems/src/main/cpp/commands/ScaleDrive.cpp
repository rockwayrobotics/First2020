#include "commands/ScaleDrive.h"
#include <iostream>

ScaleDrive::ScaleDrive(DrivebaseSubsystem* drivebase, double scale) : m_drivebase{drivebase} {
    m_scale = scale;
}

void ScaleDrive::Initialize() {
    m_drivebase->SetScale(m_scale);
    std::cout << "Left encoder distance: " << m_drivebase->GetLDistance() << std::endl;
    std::cout << "Right encoder distance: " << m_drivebase->GetRDistance() << std::endl;
    m_finished = true;
}

bool ScaleDrive::IsFinished() {
    return m_finished;
}