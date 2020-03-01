#include "commands/Braketh.h"
//Learning how to comment is rally useful so if you are reading this i sugest learning
Braketh::Braketh(DrivebaseSubsystem* Drbase, double braking_speed) {
    m_Drbase = Drbase;
    m_braking_speed = braking_speed;
    double m_speed;
    double m_current_encoder_value = Drbase->GetLDistance();
    double m_last_encoder_value;
}

void Braketh::Initialize() {
    finished = false;
}

void Braketh::Execute() {
    if(m_speed != 0){
        m_current_encoder_value = m_Drbase->GetLDistance();
        m_speed = m_last_encoder_value - m_current_encoder_value;
        m_current_encoder_value = m_last_encoder_value;
        m_braking_speed = -m_speed;
    }else{
        finished = true;
    }
    
}

bool Braketh::IsFinished() {
    return true;
    finished = false;
}
