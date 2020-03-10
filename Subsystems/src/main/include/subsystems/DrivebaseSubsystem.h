#ifndef DRIVEBASESUBSYSTEM
#define DRIVEBASESUBSYSTEM

#include <frc2/command/SubsystemBase.h>

#include "ctre/Phoenix.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/Encoder.h>

#include "RobotMap.h"

class DrivebaseSubsystem : public frc2::SubsystemBase {
    public:
        DrivebaseSubsystem();
        void Set(double y, double x, int priority);
        void SetLR(double l, double r, int priority);
        void Periodic() override;
        void SetScale(double scale);
        double GetLDistance();
        double GetRDistance();
        bool GetStopped();
        double GetLRate();
        double GetRRate();
    private:
        WPI_VictorSPX m_leftMotor1 {RobotMap::CAN::LEFTMOTOR1};
        WPI_VictorSPX m_leftMotor2 {RobotMap::CAN::LEFTMOTOR2};
        WPI_VictorSPX m_rightMotor1 {RobotMap::CAN::RIGHTMOTOR1};
        WPI_VictorSPX m_rightMotor2 {RobotMap::CAN::RIGHTMOTOR2};
        frc::DifferentialDrive m_drive1 {m_leftMotor1, m_rightMotor1};
        frc::DifferentialDrive m_drive2 {m_leftMotor2, m_rightMotor2};
        frc::Encoder m_leftEncoder {RobotMap::DIO::DBENCODERL1, RobotMap::DIO::DBENCODERL2};
        frc::Encoder m_rightEncoder {RobotMap::DIO::DBENCODERR1, RobotMap::DIO::DBENCODERR2};
        double m_y;
        double m_x;
        double m_l;
        double m_r;
        double m_scale = 1;
        bool m_usingLR;
        int m_priority = 0;
};

#endif