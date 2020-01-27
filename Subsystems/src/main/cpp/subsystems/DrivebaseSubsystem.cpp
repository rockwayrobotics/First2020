#include "subsystems/DrivebaseSubsystem.h"

DrivebaseSubsystem::DrivebaseSubsystem() {

}

void DrivebaseSubsystem::Set(double y, double x) {
    m_y = y;
    m_x = x;
}

void DrivebaseSubsystem::Periodic() {
    m_drive1.ArcadeDrive(m_y, m_x);
    m_drive2.ArcadeDrive(m_y, m_x);
}