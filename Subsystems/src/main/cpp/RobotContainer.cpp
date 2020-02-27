/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include "controls/TestControlConfig.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  Controls::ConfigureButtonBindings(m_drivebase, m_wheelSpinner, m_colourSensor, m_hopper, m_hook);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  std::cout << "I am working in robotcontainer under GetAutonomousCommad" << std::endl;
  return &m_autonomousCommand;
}

void RobotContainer::Drive(double y, double x) {
  m_drivebase.Set(y, x, 0);
}

void RobotContainer::MoveHook(double pow) {
  m_hook.Move(pow);
}

void RobotContainer::StartColourSensor() {
  m_colourSensor.SetActive(true);
  frc2::CommandScheduler::GetInstance().Schedule(&m_colourSensorUpdater);
}

void RobotContainer::StopColourSensor() {
  m_colourSensor.SetActive(false);
}