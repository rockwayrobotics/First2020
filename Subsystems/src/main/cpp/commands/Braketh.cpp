#include "commands/Braketh.h"
//Learning how to comment is rally useful so if you are reading this i sugest learning
Braketh::Braketh(DrivebaseSubsystem* Drbase) {
    m_Drbase = Drbase;
    m_braking_speed = 0;
    double m_speed = Drbase->GetLRate();
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
        std::cout << "The current speed is " << m_speed << std::endl << "The current braking speed is " << m_braking_speed << std::endl;
        if (m_speed >= 1700 && m_speed <= 1800 ){
            m_braking_speed = -1;
        }
        else if (m_speed >= 1600 && m_speed >= 1699) { //Change out valaues after testing
            m_braking_speed = -0.9;
        }
        else if (m_speed >= 1500 && m_speed <= 1799) {
            m_braking_speed = -0.8;
        }
        else if(m_speed >= 1400 && m_speed >= 1599){
            m_braking_speed = -0.7;
        }
        else if (m_speed >= 1300 && m_speed <= 1499){
            m_braking_speed = -0.6;
        }
        else if (m_speed >= 1200 && m_speed <= 1399){
            m_braking_speed = -0.5;
        }
        else if (m_speed >= 1100 && m_speed <= 1399){
            m_braking_speed = -0.4;
        }
        else if (m_speed >= 1000 && m_speed <= 1299){
            m_braking_speed = -0.3;
        }
        else if (m_speed >= 900 && m_speed <= 1199){
            m_braking_speed = -0.2;
        }
        else if (m_speed >= 800 && m_speed <= 1099){
            m_braking_speed = -0.1;
        }
    }
    else{
        finished = true;
    }
    
}

bool Braketh::IsFinished() {
    return true;
    finished = false;
}
