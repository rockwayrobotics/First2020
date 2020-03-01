/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "RobotMap.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include <frc/XboxController.h>
#include <frc/Joystick.h>

#include "controls/TestControlConfig.h"
#include "Controllers.h"

#include "commands/SpinWheelToColour.h"

#include <wpi/raw_ostream.h>
#include <cameraserver/CameraServer.h>


void Robot::RobotInit() {
  #if defined(__linux__)
    frc::CameraServer::GetInstance()->StartAutomaticCapture();
  #else
    wpi::errs() << "Vision only available on Linux.\n";
    wpi::errs().flush();
#endif
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
  m_container.StartColourSensor();
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  m_container.Drive(
    -Controllers::xbox.GetY(Controls::DriveAxis[0]),
    Controllers::xbox.GetX(Controls::DriveAxis[1])
  );
  m_container.MoveHook(Controllers::flight.GetY());
  //m_container.MoveHook(Controllers::[2]);
}

void Robot::TestInit() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
