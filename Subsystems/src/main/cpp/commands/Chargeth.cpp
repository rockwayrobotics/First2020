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
    m_targetDistanceL = m_startingDistanceL + m_distance_going;
    m_targetDistanceR = m_startingDistanceR + m_distance_going;
    m_powL = 0.5;
    m_powR = 0.5;
}

void Chargeth::Execute() {
    double curL = m_Drbase->GetLDistance();
    double curR = m_Drbase->GetRDistance();
    if (curL >= m_targetDistanceL && curR >= m_targetDistanceR) {
        finished = true;
    } else {
        m_Drbase->SetLR(m_powL, m_powR, 1);
    }
}


bool Chargeth::IsFinished() {
    return finished;
}
