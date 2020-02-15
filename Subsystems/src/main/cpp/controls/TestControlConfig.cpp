#include "controls/TestControlConfig.h"
#include "Buttons.h"
#include "commands/ScaleDrive.h"
#include "commands/SpinWheel.h"
#include "commands/SpinWheelToColour.h"
#include "commands/ToggleHopper.h"
#include <frc2/command/InstantCommand.h>

#include <iostream>

void Controls::ConfigureButtonBindings(DrivebaseSubsystem& drivebase, WheelSpinnerSubsystem& wheelSpinner, ColourSensorSubsystem& colourSensor, HopperSubsystem& hopper) {
    // Configure button bindings here
    
    Buttons::LB
        .WhenPressed(ScaleDrive {&drivebase, 0.5})
        .WhenReleased(ScaleDrive {&drivebase, 1});
    Buttons::RB
        .WhenPressed(SpinWheel {&wheelSpinner, 0});
    (!Buttons::RB && Buttons::X)
        .WhenActive(SpinWheel {&wheelSpinner, -1})
        .WhenInactive(SpinWheel {&wheelSpinner, 0});

    (!Buttons::RB && Buttons::Y)
    .WhenActive([&]() {
        hopper.Dump();
    }, {&hopper});
    (!Buttons::RB && Buttons::L)
    .WhenActive([&]() {
        hopper.Load();
    }, {&hopper});
    (!Buttons::RB && Buttons::R)
    .WhenActive([&]() {
        hopper.Off();
    }, {&hopper});
    (!Buttons::RB && Buttons::B)
    .WhenActive([&]() {
        std::cout << "Solenoid state: " << hopper.GetState() << "\n";
    }, {&hopper});

    (!Buttons::RB && Buttons::A)
        .WhenActive(ToggleHopper {&hopper});
    (Buttons::RB && Buttons::A)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::GREEN});
    (Buttons::RB && Buttons::B)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::RED});
    (Buttons::RB && Buttons::X)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::BLUE});
    (Buttons::RB && Buttons::Y)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::YELLOW});
    
}