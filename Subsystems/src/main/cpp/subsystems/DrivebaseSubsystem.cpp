#include "subsystems/DrivebaseSubsystem.h"
#include <iostream>

const double PULSESPERREVOLUTION = 1440;
const double WHEELDIAMETER = 4;
const double PI = 3.14159265358979323846;
const double DISPERPULSE = WHEELDIAMETER * PI / PULSESPERREVOLUTION;

DrivebaseSubsystem::DrivebaseSubsystem() {
    m_leftEncoder.SetDistancePerPulse(DISPERPULSE);
    m_rightEncoder.SetDistancePerPulse(DISPERPULSE);
}

void DrivebaseSubsystem::Set(double y, double x, int priority) {
    if (priority >= m_priority) {
        m_y = y;
        m_x = x;
        m_priority = priority;
    }
}

void DrivebaseSubsystem::SetScale(double scale) {
    m_scale = scale;
}

double DrivebaseSubsystem::GetLDistance() {
    return m_leftEncoder.GetDistance();
}

double DrivebaseSubsystem::GetRDistance() {
    return m_rightEncoder.GetDistance();
}

void DrivebaseSubsystem::Periodic() {
    m_drive1.ArcadeDrive(m_scale * m_y, m_scale * m_x);
    m_drive2.ArcadeDrive(m_scale * m_y, m_scale * m_x);
    m_priority = 0;
}

void DrivebaseSubsystem::SetScale(double scale) {
    m_scale = scale;
}