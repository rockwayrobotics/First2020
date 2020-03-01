#include "commands/Chargeth.h"
#include <cmath>
#include <iostream>

Chargeth::Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going) {
    AddRequirements({Drbase});
    m_Drbase = Drbase;
    m_y = y;
    m_distance_going = distance_going;
}

void Chargeth::Initialize() {
    finished = false;
    m_startingDistanceL = m_Drbase->GetLDistance(); // Store the distance on the left encoder
    m_startingDistanceR = m_Drbase->GetRDistance(); // Store the distance on the right encoder
}

void Chargeth::Execute() {
    if (std::abs(m_Drbase->GetLDistance() - m_startingDistanceL) >= m_distance_going) {
        finished = true;
    } else {
        m_Drbase->Set(m_y, 0, 1);
    }
    std::cout << "Chargething. Distance: " << std::abs(m_Drbase->GetLDistance() - m_startingDistanceL) << std::endl;
}


bool Chargeth::IsFinished() {
    return finished;
}
