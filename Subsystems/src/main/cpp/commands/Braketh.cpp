#include "commands/Braketh.h"
//Learning how to comment is rally useful so if you are reading this i sugest learning
Braketh::Braketh(DrivebaseSubsystem* Drbase) {
    m_Drbase = Drbase;
    m_left_braking_speed = 0;
    double m_left_speed = Drbase->GetLRate();
    double m_right_speed = Drbase->GetRRate();
}

void Braketh::Initialize() {
    finished = false;
}

void Braketh::Execute() {
    m_left_speed = m_Drbase->GetLRate();
    m_right_speed = m_Drbase->GetRRate();
    m_left_braking_speed = -m_left_speed;
    std::cout << "The current left speed is " << m_left_speed << std::endl << "The current left braking speed is " << m_left_braking_speed << std::endl;
    m_right_braking_speed = -m_right_speed;
    std::cout << "The current right speed is " << m_right_speed << std::endl << "The current right braking speed is " << m_right_braking_speed << std::endl;
    if (m_left_speed >= 1700 && m_left_speed <= 1800 ){
        m_left_braking_speed = -1;
    }
    else if (m_left_speed >= 1600 && m_left_speed >= 1699) { //Change out valaues after testing
        m_left_braking_speed = -0.9;
    }
    else if (m_left_speed >= 1500 && m_left_speed <= 1799) {
        m_left_braking_speed = -0.8;
    }
    else if(m_left_speed >= 1400 && m_left_speed >= 1599){
        m_left_braking_speed = -0.7;
    }
    else if (m_left_speed >= 1300 && m_left_speed <= 1499){
        m_left_braking_speed = -0.6;
    }
    else if (m_left_speed >= 1200 && m_left_speed <= 1399){
        m_left_braking_speed = -0.5;
    }
    else if (m_left_speed >= 1100 && m_left_speed <= 1399){
        m_left_braking_speed = -0.4;
    }
    else if (m_left_speed >= 1000 && m_left_speed <= 1299){
        m_left_braking_speed = -0.3;
    }
    else if (m_left_speed >= 900 && m_left_speed <= 1199){
        m_left_braking_speed = -0.2;
    }
    else if (m_left_speed > 0){
        m_left_braking_speed = -0.1;
    }
    else {
        finished = true;
    }
        
    
}

bool Braketh::IsFinished() {
    return true;
    finished = false;
}
