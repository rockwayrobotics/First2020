/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

#include <rev/ColorSensorV3.h>

#include "RobotMap.h"

#include <cameraserver/CameraServer.h>
#include <frc/TimedRobot.h>
#include <wpi/raw_ostream.h>

/**
 * Uses the CameraServer class to automatically capture video from a USB webcam
 * and send it to the FRC dashboard without doing any vision processing. This is
 * the easiest way to get camera images to the dashboard. Just add this to the
 * RobotInit() method in your program.
 */

/**
 * This is a simple example to show the values that can be read from the REV
 * Color Sensor V3
 */
class Robot : public frc::TimedRobot {
  /**
   * Change the I2C port below to match the connection of your color sensor
   */
  frc::PWMVictorSPX m_leftMotor{RobotMap.LEFTMOTOR1};
  frc::PWMVictorSPX m_leftMotor2{RobotMap.LEFTMOTOR2};
  frc::PWMVictorSPX m_rightMotor{RobotMap.RIGHTMOTOR1};
  frc::PWMVictorSPX m_rightMotor2{RobotMap.RIGHTMOTOR2}; 
  frc::PWMVictorSPX m_winchMotor{RobotMap.WINCHMOTOR};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::DifferentialDrive m_robotDrive2{m_leftMotor2, m_rightMotor2};
  frc::XboxController m_stick{RobotMap.XBOX};
  frc::Joystick m_stick2{RobotMap.FLIGHT};

  const struct {
    const frc::GenericHID::JoystickHand left = frc::GenericHID::JoystickHand::kLeftHand;
    const frc::GenericHID::JoystickHand right = frc::GenericHID::JoystickHand::kRightHand;
  } Hand;

  std::string startingColour = "";
  int rotations = 0;
  bool onStartingColour = false;

  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  /**
   * A Rev Color Sensor V3 object is constructed with an I2C port as a 
   * parameter. The device will be automatically initialized with default 
   * parameters.
   */
  rev::ColorSensorV3 m_colorSensor{i2cPort};

 public:
  void RobotInit() override {
#if defined(__linux__)
    frc::CameraServer::GetInstance()->StartAutomaticCapture();
#else
    wpi::errs() << "Vision only available on Linux.\n";
    wpi::errs().flush();
#endif
  }
  void RobotPeriodic() {
    /**
     * The method GetColor() returns a normalized color value from the sensor and can be
     * useful if outputting the color to an RGB LED or similar. To
     * read the raw color, use GetRawColor().
     * 
     * The color sensor works best when within a few inches from an object in
     * well lit conditions (the built in LED is a big help here!). The farther
     * an object is the more light from the surroundings will bleed into the 
     * measurements and make it difficult to accurately determine its color.
     */
    frc::Color detectedColor = m_colorSensor.GetColor();

    /**
     * The sensor returns a raw IR value of the infrared light detected.
     */
    double IR = m_colorSensor.GetIR();

    /**
     * Find values of rgb
     */
    std::string colour = "";
    bool colourRed = false;
    if (detectedColor.red > .37) {
      colour += "red";
      colourRed = true;
    }
    bool colourBlue = false;
    if (detectedColor.blue > .3) {
      colour += "blue";
      colourBlue = true;
    }
    bool colourGreen = false;
    bool colourYellow = false;
    if (detectedColor.green > .5) {
      if (detectedColor.red > .3) {
        colour += "yellow";
        colourYellow = true;
      } else {
        colour += "green";
        colourGreen = true;
      }
    }
    if (startingColour == "") {
      if (colour != "") {
        startingColour = colour;
        onStartingColour = true;
      }
    } else if (startingColour == colour) {
      if (!onStartingColour) {
        rotations++;
        onStartingColour = true;
      }
    } else {
      onStartingColour = false;
    }


    /**
     * Open Smart Dashboard or Shuffleboard to see the color detected by the 
     * sensor.
     */
    frc::SmartDashboard::PutNumber("Red value", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green Value", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue value", detectedColor.blue);
    //frc::SmartDashboard::PutBoolean("Red is True", colourRed);
    //frc::SmartDashboard::PutBoolean("Blue is True", colourBlue);
    //frc::SmartDashboard::PutBoolean("Green is True", colourGreen);
    //frc::SmartDashboard::PutBoolean("Yellow is True", colourYellow);
    frc::SmartDashboard::PutString("Current colour", colour);
    frc::SmartDashboard::PutString("Starting colour", startingColour);
    frc::SmartDashboard::PutNumber("Current rotations", (float)rotations / 2.0);
    //frc::SmartDashboard::PutNumber("IR", IR);

    /**
     * In addition to RGB IR values, the color sensor can also return an 
     * infrared proximity value. The chip contains an IR led which will emit
     * IR pulses and measure the intensity of the return. When an object is 
     * close the value of the proximity will be large (max 2047 with default
     * settings) and will approach zero when the object is far away.
     * 
     * Proximity can be used to roughly approximate the distance of an object
     * or provide a threshold for when an object is close enough to provide
     * accurate color values.
     */
    uint32_t proximity = m_colorSensor.GetProximity();

    frc::SmartDashboard::PutNumber("Proximity", proximity);
  }
  void TeleopPeriodic() {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(-m_stick.GetY(Hand.left) * 0.7, m_stick.GetX(Hand.left) * 0.7);
    m_robotDrive2.ArcadeDrive(-m_stick.GetY(Hand.left), m_stick.GetX(Hand.left));
    m_winchMotor.Set((m_stick.GetY(Hand.right)));
    /*if (m_stick.GetRawButton(13)) {
      m_rightMotor.Set(.8);
      m_rightMotor2.Set(.8);
      m_leftMotor.Set(0);
      m_leftMotor2.Set(0);
    }
    else if (m_stick.GetRawButton(14)) {
      m_leftMotor.Set(.8);
      m_leftMotor2.Set(.8);
      m_rightMotor.Set(0);
      m_rightMotor2.Set(0);
    }*/
    
    /*if (m_stick.GetAButton()) {
      m_winchMotor.Set(.15);
    }  else if (m_stick.GetXButton())
    {
      m_winchMotor.Set(-.15);
    } else
    {
      m_winchMotor.Set(0);
    }*/

    if (m_stick.GetAButton()) {
      //c->SetClosedLoopControl(true);
    } else
    {
      //c->SetClosedLoopControl(false);
    }
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif