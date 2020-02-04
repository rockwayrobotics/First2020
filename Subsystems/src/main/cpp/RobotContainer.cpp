/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include "controls/TestControlConfig.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  Controls::ConfigureButtonBindings(m_drivebase);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

void RobotContainer::Drive(double y, double x) {
  m_drivebase.Set(y, x);
}

void RobotContainer::StartColourSensor() {
  m_colourSensor.SetActive(true);
  frc2::CommandScheduler::GetInstance().Schedule(&m_colourSensorUpdater);
}

void RobotContainer::StopColourSensor() {
  m_colourSensor.SetActive(false);
}