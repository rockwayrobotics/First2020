#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>

#include "RobotMap.h"

class DrivebaseSubsystem : frc2::SubsystemBase {
    public:
        DrivebaseSubsystem();
        void Set(double y, double x);
        void Periodic() override;
    private:
        frc::PWMVictorSPX m_leftMotor1 {RobotMap.LEFTMOTOR1};
        frc::PWMVictorSPX m_leftMotor2 {RobotMap.LEFTMOTOR2};
        frc::PWMVictorSPX m_rightMotor1 {RobotMap.RIGHTMOTOR1};
        frc::PWMVictorSPX m_rightMotor2 {RobotMap.RIGHTMOTOR2};
        frc::DifferentialDrive m_drive1 {m_leftMotor1, m_rightMotor1};
        frc::DifferentialDrive m_drive2 {m_leftMotor2, m_rightMotor2};
        double m_y;
        double m_x;
};