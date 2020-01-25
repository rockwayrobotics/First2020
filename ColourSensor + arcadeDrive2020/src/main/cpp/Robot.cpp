/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/drive/DifferentialDrive.h>

#include "rev/ColorSensorV3.h"

/**
 * This is a simple example to show the values that can be read from the REV
 * Color Sensor V3
 */
class Robot : public frc::TimedRobot {
  /**
   * Change the I2C port below to match the connection of your color sensor
   */
  frc::PWMVictorSPX m_leftMotor{2};
  frc::PWMVictorSPX m_leftMotor2{1};
  frc::PWMVictorSPX m_rightMotor{3};
  frc::PWMVictorSPX m_rightMotor2{4};
  frc::PWMVictorSPX m_wheelMotor{5};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::DifferentialDrive m_robotDrive2{m_leftMotor2, m_rightMotor2};
  frc::Joystick m_stick{0};
  frc::Joystick m_stick2{1};

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
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    //frc::SmartDashboard::PutBoolean("Red is True", colourRed);
    //frc::SmartDashboard::PutBoolean("Blue is True", colourBlue);
    //frc::SmartDashboard::PutBoolean("Green is True", colourGreen);
    //frc::SmartDashboard::PutBoolean("Yellow is True", colourYellow);
    frc::SmartDashboard::PutString("Colour", colour);
    frc::SmartDashboard::PutString("Starting Colour", startingColour);
    frc::SmartDashboard::PutNumber("Rotations", (float)rotations / 2.0);
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
    m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
    m_robotDrive2.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
    m_wheelMotor.Set(m_stick2.GetTwist());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif