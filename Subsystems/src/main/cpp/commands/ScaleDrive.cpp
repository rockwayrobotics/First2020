#include "commands/ScaleDrive.h"

ScaleDrive::ScaleDrive(DrivebaseSubsystem* drivebase, double scale) : m_drivebase{drivebase} {
    m_scale = scale;
}

void ScaleDrive::Initialize() {
    m_drivebase->SetScale(m_scale);
    m_finished = true;
}

bool ScaleDrive::IsFinished() {
    return m_finished;
}