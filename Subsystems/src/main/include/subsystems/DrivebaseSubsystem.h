#ifndef DRIVEBASESUBSYSTEM
#define DRIVEBASESUBSYSTEM

#include <frc2/command/SubsystemBase.h>

#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Encoder.h>

#include "RobotMap.h"

class DrivebaseSubsystem : frc2::SubsystemBase {
    public:
        DrivebaseSubsystem();
        void Set(double y, double x);
        void SetScale(double scale);
        double GetLDistance();
        double GetRDistance();
        void Periodic() override;
    private:
        frc::PWMVictorSPX m_leftMotor1 {RobotMap::Motors::LEFTMOTOR1};
        frc::PWMVictorSPX m_leftMotor2 {RobotMap::Motors::LEFTMOTOR2};
        frc::PWMVictorSPX m_rightMotor1 {RobotMap::Motors::RIGHTMOTOR1};
        frc::PWMVictorSPX m_rightMotor2 {RobotMap::Motors::RIGHTMOTOR2};
        frc::DifferentialDrive m_drive1 {m_leftMotor1, m_rightMotor1};
        frc::DifferentialDrive m_drive2 {m_leftMotor2, m_rightMotor2};
        frc::Encoder m_leftEncoder {RobotMap::DIO::DBENCODERL1, RobotMap::DIO::DBENCODERL2};
        frc::Encoder m_rightEncoder {RobotMap::DIO::DBENCODERR1, RobotMap::DIO::DBENCODERR2};
        double m_y;
        double m_x;
        double m_scale = 0;
};

#endif