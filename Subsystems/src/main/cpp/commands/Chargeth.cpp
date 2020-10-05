#include "commands/Chargeth.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <cmath>
#include <iostream>

const double SCALE = 0.001;

Chargeth::Chargeth(DrivebaseSubsystem* Drbase, double speed, double distance_going, int timeout) {
    AddRequirements({Drbase});
    m_Drbase = Drbase;
    m_speed = speed;
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
    if (m_distance_going > 0) {
        m_backwards = 1;
    } else {
        m_backwards = -1;
    }
    frc::SmartDashboard::PutNumber("target l", m_targetDistanceL);
    frc::SmartDashboard::PutNumber("target r", m_targetDistanceR);
}

void Chargeth::Execute() {
    double curL = m_Drbase->GetLDistance();
    double curR = m_Drbase->GetRDistance();
    frc::SmartDashboard::PutNumber("left power", m_powL);
    frc::SmartDashboard::PutNumber("right power", m_powR);
    frc::SmartDashboard::PutNumber("curL", curL);
    frc::SmartDashboard::PutNumber("curR", curR);
    if (m_backwards * curL >= m_backwards * m_targetDistanceL
     && m_backwards * curR >= m_backwards * m_targetDistanceR) {
        finished = true;
    } else {
        m_Drbase->SetLR(m_backwards * m_powL, m_backwards * m_powR, 1);
        double completedL = 1 - (m_targetDistanceL - curL) / m_distance_going;
        double completedR = 1 - (m_targetDistanceR - curR) / m_distance_going;
        frc::SmartDashboard::PutNumber("completedL", completedL);
        frc::SmartDashboard::PutNumber("completedR", completedR);
        if (completedL > completedR) {
            m_powR += SCALE;
            m_powL -= SCALE;
        } else if (completedL < completedR) {
            m_powR -= SCALE;
            m_powL += SCALE;
        }
    }
}


bool Chargeth::IsFinished() {
    return finished;
}