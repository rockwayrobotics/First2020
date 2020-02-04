#include "controls/TestControlConfig.h"
#include "commands/ScaleDrive.h"

#include <frc/Joystick.h>
#include <frc/XboxController.h>

#include <frc2/command/button/JoystickButton.h>

frc::XboxController xbox {RobotMap::Controllers::XBOX};
frc::Joystick flight {RobotMap::Controllers::FLIGHT};

void Controls::ConfigureButtonBindings(DrivebaseSubsystem& drivebase) {
    // Configure button bindings here
    frc2::Button halfScaleButton{[&] { return xbox.GetRawButton((int)frc::XboxController::Button::kBumperLeft); }};
    halfScaleButton.WhenPressed(ScaleDrive {&drivebase, 0.5});
    halfScaleButton.WhenReleased(ScaleDrive {&drivebase, 1});
}