#include "commands/SpinWheelToColour.h"
#include <iostream>

SpinWheelToColour::SpinWheelToColour(WheelSpinnerSubsystem* wheel, ColourSensorSubsystem* colour, RobotMap::Colour target) {
    m_wheel = wheel;
    m_colour = colour;
    m_target = target;
    AddRequirements({m_wheel, m_colour});
}

void SpinWheelToColour::Initialize() {
    std::cout << "starting spin" << std::endl;
    m_finished = false;
    m_wheel->Spin(0.2);
}

void SpinWheelToColour::Execute() {
    m_colour->Update();
    if (m_colour->colour == m_target) {
        std::cout << "found colour" << std::endl;
        m_wheel->Spin(0);
        m_finished = true;
    }
}

void SpinWheelToColour::End(bool interrupted) {
    if (interrupted) {
        std::cout << "spin cancelled" << std::endl;
    }
    std::cout << "stopping spin" << std::endl;
}

bool SpinWheelToColour::IsFinished() {
    return m_finished;
}

void SpinWheelToColour::Stop() {
    std::cout << "spin stopped" << std::endl;
    m_finished = true;
}