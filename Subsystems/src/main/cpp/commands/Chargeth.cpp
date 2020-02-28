#include "commands/Chargeth.h"
#include <cmath>

Chargeth::Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going) {
    m_Drbase = Drbase;
    m_y = y;
    m_distance_going = distance_going;
}

void Chargeth::Initialize() {
    finished = false;
    m_distance_travelled = m_Drbase->GetLDistance(); // Makes distance equal to the distance travelled by the left encoder
}

void Chargeth::Execute() {
    if (std::abs(m_Drbase->GetLDistance() - m_distance_travelled) > m_distance_going) {
        finished = true;
    } else {
        m_Drbase->Set(m_y, 0, 1);
    }
}


bool Chargeth::IsFinished() {
    return finished;
}
