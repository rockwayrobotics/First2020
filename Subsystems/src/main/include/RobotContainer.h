/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTCONTAINER
#define ROBOTCONTAINER

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"

#include "commands/UpdateColourSensor.h"

#include "subsystems/ColourSensorSubsystem.h"
#include "subsystems/DrivebaseSubsystem.h"
#include "subsystems/WheelSpinnerSubsystem.h"
#include "subsystems/HopperSubsystem.h"
#include "subsystems/HookSubsystem.h"

#include "commands/AutonomousCode.h"
#include "commands/Driveth.h"

#include "RobotMap.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  void StartColourSensor();
  void StopColourSensor();
  void Drive(double y, double x);
  void MoveHook(double pow);
  

 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ColourSensorSubsystem m_colourSensor;
  DrivebaseSubsystem m_drivebase;
  UpdateColourSensor m_colourSensorUpdater {&m_colourSensor};
  WheelSpinnerSubsystem m_wheelSpinner;
  HopperSubsystem m_hopper;
  HookSubsystem m_hook;
  //Autonomous m_autonomous;
  Autonomous m_autonomousCommand {&m_drivebase, &m_hopper};
  

  void ConfigureButtonBindings();
};

#endif