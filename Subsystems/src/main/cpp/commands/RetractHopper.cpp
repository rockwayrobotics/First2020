#include "commands/RetractHopper.h"

const int CYCLESPERTOGGLE = 5;
const int TOGGLES = 20;

RetractHopper::RetractHopper(HopperSubsystem* hopper) {
    AddRequirements(hopper);
    m_hopper = hopper;
}

void RetractHopper::Initialize() {
    m_cycleCount = 0;
    m_toggleCount = 0;
    m_off = false;
}

void RetractHopper::Execute() {
    if (!m_off) {
        if (m_cycleCount == CYCLESPERTOGGLE) {
            m_hopper->Off();
            m_off = true;
            m_toggleCount++;
            if (m_toggleCount == TOGGLES) {
                m_finished = true;
            }
            m_cycleCount = 0;
        } else {
            m_cycleCount++;
        }
    } else {
        m_hopper->SetLoad();
        m_off = false;
    }
}

bool RetractHopper::IsFinished() {
    return m_finished;
}