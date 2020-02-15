#include "subsystems/DrivebaseSubsystem.h"
#include <iostream>

DrivebaseSubsystem::DrivebaseSubsystem() {
}

void DrivebaseSubsystem::Set(double y, double x, int priority) {
    if (priority >= m_priority) {
        m_y = y;
        m_x = x;
        m_priority = priority;
    }
}

void DrivebaseSubsystem::Periodic() {
    m_drive1.ArcadeDrive(m_scale * m_y, m_scale * m_x);
    m_drive2.ArcadeDrive(m_scale * m_y, m_scale * m_x);
    m_priority = 0;
}

void DrivebaseSubsystem::SetScale(double scale) {
    m_scale = scale;
}