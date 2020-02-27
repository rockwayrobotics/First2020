#include "commands/Driveth.h"
int b = 0;


Driveth::Driveth(DrivebaseSubsystem* Drbase, double y, double x, int time) {
    m_Drbase = Drbase;
    m_y = y;
    m_x = x;
    m_time = time;
}

void Driveth::Initialize() {
    finished = false;
    b = 0;
}

void Driveth::Execute() {
    b++;
    m_Drbase->Set(m_y, m_x, 1);
    if (b == m_time){
        finished = true;
    }
    
    

    std::cout << "Working" << b << std::endl;
}


bool Driveth::IsFinished() {
    return finished;
    finished = false;
}
