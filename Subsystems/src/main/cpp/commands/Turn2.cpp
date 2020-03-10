/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Turn2.h"

Turn2::Turn2(DrivebaseSubsystem* drivebase, double pow, double cyc) {
  // Use addRequirements() here to declare subsystem dependencies.
  m_drivebase = drivebase;
  m_pow = pow;
  m_cyc = cyc;
  AddRequirements({drivebase});
}

// Called when the command is initially scheduled.
void Turn2::Initialize() {
  curCyc = 0;
}

// Called repeatedly when this Command is scheduled to run
void Turn2::Execute() {
  curCyc++;
  m_drivebase->Set(0, m_pow, 1);
}

// Called once the command ends or is interrupted.
void Turn2::End(bool interrupted) {
  m_drivebase->Set(0, 0, 0);
}

// Returns true when the command should end.
bool Turn2::IsFinished() { return curCyc > m_cyc; }
