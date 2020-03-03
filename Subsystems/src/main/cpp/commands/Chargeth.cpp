#include "commands/Chargeth.h"
#include <cmath>
#include <iostream>

Chargeth::Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going, int timeout) {
    AddRequirements({Drbase});
    m_Drbase = Drbase;
    m_y = y;
    m_distance_going = distance_going;
    m_timeout = timeout;
}

void Chargeth::Initialize() {
    finished = false;
    m_startingDistanceL = m_Drbase->GetLDistance(); // Store the distance on the left encoder
    m_startingDistanceR = m_Drbase->GetRDistance(); // Store the distance on the right encoder
    m_cycles = 0;
}

void Chargeth::Execute() {
    if (std::abs(m_Drbase->GetLDistance() - m_startingDistanceL) >= m_distance_going
        || (m_cycles > 5 && m_Drbase->GetStopped())
        || (m_timeout > 0 && m_cycles >= m_timeout)) {
        finished = true;
    } else {
        m_Drbase->Set(m_y, 0, 1);
        m_cycles++;
    }
}


bool Chargeth::IsFinished() {
    return finished;
}
