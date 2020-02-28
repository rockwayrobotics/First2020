#include "commands/Chargeth.h"

//int b = 0;
bool while_loop_Chargeth_Length = false; //This is definetly not needed but I am not good. This is used to keep chargeth going until it has gone specific distacne.


Chargeth::Chargeth(DrivebaseSubsystem* Drbase, double y, double distance_going) {
    m_Drbase = Drbase;
    m_y = y;
    m_distance_going = distance_going;
    m_distance_travelled = m_Drbase->GetLDistance(); // Makes distance equal to the distance travelled by the left encoder
}

void Chargeth::Initialize() {
    finished = false;
   // b = 0;
}

void Chargeth::Execute() {
   // b++;
    m_Drbase->Set(m_y, 0, 1);
    m_Drbase->SetDistance_Going(m_distance_going); //Sets the distance that the thing has to go
    if (m_distance_going == m_distance_travelled){
        finished = true;
    }
    //if (b == m_time){
      //  finished = true;
    //}
    
    

    //std::cout << "Working" << b << std::endl;
}


bool Chargeth::IsFinished() {
    return finished;
    finished = false;
}
