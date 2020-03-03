#include "controls/TestControlConfig.h"
#include "Buttons.h"
#include "commands/ScaleDrive.h"
#include "commands/SpinWheel.h"
#include "commands/SpinWheelToColour.h"
#include "commands/ToggleHopper.h"
#include "commands/MoveHookTo.h"
#include "commands/Chargeth.h"
#include <frc2/command/InstantCommand.h>
#include "commands/Driveth.h"

#include <iostream>

void Controls::ConfigureButtonBindings(DrivebaseSubsystem& drivebase, WheelSpinnerSubsystem& wheelSpinner, ColourSensorSubsystem& colourSensor, HopperSubsystem& hopper, HookSubsystem& hook) {
    // Configure button bindings here
    
    XboxButtons::LB
        .WhenPressed(ScaleDrive {&drivebase, 0.5})
        .WhenReleased(ScaleDrive {&drivebase, 1});
    XboxButtons::RB
        .WhenPressed(SpinWheel {&wheelSpinner, 0});
    
    XboxButtons::RT
        .WhenActive(MoveHookTo {&hook, 0.8});
    XboxButtons::LT
        .WhenActive(MoveHookTo {&hook, 0.5});

    (!XboxButtons::RB && XboxButtons::X)
        .WhenActive(SpinWheel {&wheelSpinner, -1})
        .WhenInactive(SpinWheel {&wheelSpinner, 0});
    //(!XboxButtons::RB && XboxButtons::Y)
      //  .WhenActive([&]() {
        //    hopper.Toggle();
        //}, {&hopper});
    //XboxButtons::L
      //  .WhenPressed([&]() { hopper.FlapOut(); })
        //.WhenReleased([&]() { hopper.FlapIn(); });
    (!XboxButtons::RB && XboxButtons::B)
        .WhenActive([&]() {
            std::cout << "Solenoid state: " << hopper.GetState() << "\n";
            std::cout << "Left encoder value: " << drivebase.GetLDistance() << "\n";
            std::cout << "Right encoder value: " << drivebase.GetRDistance() << "\n";
        }, {&hopper});
    //(!XboxButtons::RB && XboxButtons::A)
      //  .WhenActive(ToggleHopper {&hopper});
    
    (XboxButtons::RB && XboxButtons::A)
         .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::GREEN});
    (XboxButtons::RB && XboxButtons::B)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::RED});
    (XboxButtons::RB && XboxButtons::X)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::BLUE});
    (XboxButtons::RB && XboxButtons::Y)
        .WhenActive(SpinWheelToColour {&wheelSpinner, &colourSensor, RobotMap::Colour::YELLOW});
    /*(XboxButtons::LB && XboxButtons::RB)
        .WhenActive(Driveth{&drivebase}); This is the code that absolutly destryoed the tables and this is a momento to that code and moment. Today we say good bye to a good friend and terrible enemy for we always miss you i loved you with all my heart and i hope that one day your 1s and 0s may one day forgive my poor soul for ever and ever I will see you on the other side Joe I know what you did and I will never forgive you if you go through with it */
    FlightButtons::Trigger9
        .WhenActive([&]() {std:: cout << "Yote the button be pressed9" << std::endl;});
    FlightButtons::Trigger1
        //.WhenActive(MoveHookTo {&hook, 1});
        .WhenActive(ToggleHopper {&hopper});
    FlightButtons::Trigger2
        //.WhenActive(MoveHookTo {&hook, 0});
        .WhenPressed([&]() { hopper.FlapOut(); })
        .WhenReleased([&]() { hopper.FlapIn(); });
    FlightButtons::Trigger8
        .WhenPressed([&]() { hopper.FlapOut(); });
    FlightButtons::Trigger9
        .WhenPressed([&]() { hopper.FlapIn(); });
/*    FlightButtons::Trigger3
        .WhenActive(ToggleHopper {&hopper});
    FlightButtons::Trigger4
        .WhenActive([&]() {
            hopper.Toggle();
        }, {&hopper});*/
    FlightButtons::Trigger5
        .WhenActive([&]() {std:: cout << "Yote the button be pressed5" << std::endl;});
    FlightButtons::Trigger6
        .WhenActive([&]() {std:: cout << "Yote the button be pressed6" << std::endl;});
    FlightButtons::Trigger7
        .WhenActive([&]() {std:: cout << "Yote the button be pressed7" << std::endl;});
    FlightButtons::Trigger8
        .WhenActive([&]() {std:: cout << "Yote the button be pressed8" << std::endl;});
    //FlightButtons::Trigger9
      //  .WhenActive([&]() {std:: cout << "Yote the button be pressed" << std::endl;});
    
    
}