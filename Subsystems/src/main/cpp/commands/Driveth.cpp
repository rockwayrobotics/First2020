#include "commands/Driveth.h"
int a = 0;
int b = 0;


Driveth::Driveth(DrivebaseSubsystem* Drbase) {
    m_Drbase = Drbase;
}

void Driveth::Initialize() {
    finished = false;
}

void Driveth::Execute() {
    double x,y;
    x = 0;
    y = 0.3;
    b++;
    m_Drbase->Set(y,x, 1);
    if (b == 50){
        a++;
        b = 0;
    }
    
    

    std::cout << "Working" << a << std::endl;
    if (a == 1){
        finished = true;
        a = 0;
        b = 0;
    }
}


bool Driveth::IsFinished() {
    return finished;
    finished = false;
}
