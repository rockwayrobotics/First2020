#include "subsystems/DrivebaseSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>

const double PULSESPERREVOLUTION = 360;
const double WHEELDIAMETER = 6;
const double PI = 3.14159265358979323846;
const double DISPERPULSE = WHEELDIAMETER * PI / PULSESPERREVOLUTION;

DrivebaseSubsystem::DrivebaseSubsystem() {
    m_leftEncoder.SetDistancePerPulse(DISPERPULSE); // left encoder spins positive when robot goes forward
    m_rightEncoder.SetDistancePerPulse(-DISPERPULSE); // right encoder spins negative when robot goes forward
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
    m_l = 0;
    m_r = 0;
    m_x = 0;
    m_y = 0;
    m_usingLR = false;
}

void DrivebaseSubsystem::Set(double y, double x, int priority) {
    if (priority >= m_priority) {
        m_y = y;
        m_x = x;
        m_priority = priority;
        m_usingLR = false;
    }
}

void DrivebaseSubsystem::SetLR(double l, double r, int priority) {
    if (priority >= m_priority) {
        m_l = l;
        m_r = r;
        m_priority = priority;
        m_usingLR = true;
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

double DrivebaseSubsystem::GetLRate() {
    return m_leftEncoder.GetRate();
}

double DrivebaseSubsystem::GetRRate() {
    return m_rightEncoder.GetRate();
}

bool DrivebaseSubsystem::GetStopped() {
    return m_leftEncoder.GetStopped() && m_rightEncoder.GetStopped();
}

void DrivebaseSubsystem::Periodic() {
    if (m_usingLR) {
        m_drive1.TankDrive(m_scale * m_l, m_scale * m_r, false);
        m_drive2.TankDrive(m_scale * m_l, m_scale * m_r, false);
    } else {
        m_drive1.ArcadeDrive(m_scale * m_y, m_scale * m_x);
        m_drive2.ArcadeDrive(m_scale * m_y, m_scale * m_x);
    }

    m_priority = 0;

    frc::SmartDashboard::PutNumber("Left encoder", m_leftEncoder.Get());
    frc::SmartDashboard::PutNumber("Right encoder", m_rightEncoder.Get());
    frc::SmartDashboard::PutNumber("Left encoder distance", m_leftEncoder.GetDistance());
    frc::SmartDashboard::PutNumber("Right encoder distance", m_rightEncoder.GetDistance());
    m_x = 0;
    m_y = 0;
    m_l = 0;
    m_r = 0;
}