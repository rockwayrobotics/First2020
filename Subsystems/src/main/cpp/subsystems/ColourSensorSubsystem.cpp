#include "subsystems/ColourSensorSubsystem.h"

ColourSensorSubsystem::ColourSensorSubsystem() {

}

void ColourSensorSubsystem::Update() {
    m_currentColour = m_colourSensor.GetColor();
    if (m_currentColour.red > REDTHRESHOLD) {
        colour = RobotMap::Colour::RED;
    } else if (m_currentColour.blue > BLUETHRESHOLD) {
        colour = RobotMap::Colour::BLUE;
    } else if (m_currentColour.green > GREENTHRESHOLD) {
        if (m_currentColour.red > YELLOWREDTHRESHOLD) {
            colour = RobotMap::Colour::YELLOW;
        } else {
            colour = RobotMap::Colour::GREEN;
        }
    } else {
        colour = RobotMap::Colour::NONE;
    }
    if (startingColour == RobotMap::Colour::NONE && colour != RobotMap::Colour::NONE) {
        startingColour = colour;
        onStartingColour = true;
    } else if (startingColour == colour) {
        if (!onStartingColour) {
            rotations++;
        }
    } else {
        onStartingColour = false;
    }
    frc::SmartDashboard::PutNumber("Colour", colour);
}

void ColourSensorSubsystem::SetActive(bool state) {
    m_active = state;
}

bool ColourSensorSubsystem::IsActive() {
    return m_active;
}