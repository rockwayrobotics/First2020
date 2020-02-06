#pragma once

#include <frc2/command/button/Button.h>
#include "Controllers.h"

const double triggerThreshold = 0.8;

namespace Buttons {
    frc2::Button A {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kA); }};
    frc2::Button B {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kB); }};
    frc2::Button X {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kX); }};
    frc2::Button Y {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kY); }};
    frc2::Button RB {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kBumperRight); }};
    frc2::Button LB {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kBumperLeft); }};
    frc2::Button RT {[&] { return Controllers::xbox.GetTriggerAxis(frc::XboxController::JoystickHand::kRightHand) >= triggerThreshold; }};
    frc2::Button LT {[&] { return Controllers::xbox.GetTriggerAxis(frc::XboxController::JoystickHand::kLeftHand) >= triggerThreshold; }};
    frc2::Button L {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kStickLeft); }};
    frc2::Button R {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kStickRight); }};
    frc2::Button Start {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kStart); }};
    frc2::Button Back {[&] { return Controllers::xbox.GetRawButton((int)frc::XboxController::Button::kBack); }};
}