#include "subsystems/ColourSensorSubsystem.h"

ColourSensorSubsystem::ColourSensorSubsystem() {

}

void ColourSensorSubsystem::Update() {
    m_currentColour = m_colourSensor.GetColor();
    if (m_currentColour.red > REDTHRESHOLD) {
        colour = "red";
    } else if (m_currentColour.blue > BLUETHRESHOLD) {
        colour = "blue";
    } else if (m_currentColour.green > GREENTHRESHOLD) {
        if (m_currentColour.red > YELLOWREDTHRESHOLD) {
            colour = "yellow";
        } else {
            colour = "green";
        }
    }
    if (startingColour == "" && colour != "") {
        startingColour = colour;
        onStartingColour = true;
    } else if (startingColour == colour) {
        if (!onStartingColour) {
            rotations++;
        }
    } else {
        onStartingColour = false;
    }
    frc::SmartDashboard::PutString("Colour ", colour);
}

void ColourSensorSubsystem::SetActive(bool state) {
    m_active = state;
}

bool ColourSensorSubsystem::IsActive() {
    return m_active;
}