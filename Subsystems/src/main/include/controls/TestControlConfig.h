#ifndef TESTCONTROLCONFIG
#define TESTCONTROLCONFIG

#include "Robot.h"

#include <frc/GenericHID.h>

namespace Controls {
    const frc::GenericHID::JoystickHand DriveAxis[] = {
        frc::GenericHID::JoystickHand::kLeftHand, // forward-backward stick
        frc::GenericHID::JoystickHand::kLeftHand  // left-right stick
    };
    void ConfigureButtonBindings(DrivebaseSubsystem& drivebase, WheelSpinnerSubsystem& wheelSpinner, ColourSensorSubsystem& colourSensor, HopperSubsystem& hopper, HookSubsystem& hook);
}

#endif