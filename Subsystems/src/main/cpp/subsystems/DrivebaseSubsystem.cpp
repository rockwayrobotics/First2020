#include "subsystems/DrivebaseSubsystem.h"
#include <iostream>

const double PULSESPERREVOLUTION = 360;
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
    std::cout << "left encoder pulses: " << m_leftEncoder.Get() << std::endl;
    if (m_leftEncoder.GetStopped() || m_rightEncoder.GetStopped()) {
        std::cout << "encoder not turning" << std::endl;
    }
    return m_leftEncoder.GetDistance();
}

double DrivebaseSubsystem::GetRDistance() {
    std::cout << "right encoder pulses: " << m_rightEncoder.Get() << std::endl;
    return m_rightEncoder.GetDistance();
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

    m_x = 0;
    m_y = 0;
    m_l = 0;
    m_r = 0;
}