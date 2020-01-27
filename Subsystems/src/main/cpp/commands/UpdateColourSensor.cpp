#include "commands/UpdateColourSensor.h"

UpdateColourSensor::UpdateColourSensor(ColourSensorSubsystem* colourSensor) : m_colourSensor(colourSensor) {
    AddRequirements({colourSensor});
}

void UpdateColourSensor::Execute() {
    m_colourSensor->Update();
}

bool UpdateColourSensor::IsFinished() {
    return !m_colourSensor->IsActive();
}