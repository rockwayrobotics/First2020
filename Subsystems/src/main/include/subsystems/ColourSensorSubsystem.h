#ifndef COLOURSENSORSUBSYSTEM
#define COLOURSENSORSUBSYSTEM

#include <frc2/command/SubsystemBase.h>

#include <rev/ColorSensorV3.h>

#include "../RobotMap.h"
#include <frc/smartdashboard/SmartDashboard.h>

class ColourSensorSubsystem : public frc2::SubsystemBase {
    public:
        ColourSensorSubsystem();
        void Update();
        std::string colour;
        int rotations;
        void SetActive(bool state);
        bool IsActive();
    private:
        rev::ColorSensorV3 m_colourSensor{RobotMap::COLOURSENSOR};
        frc::Color m_currentColour;
        const double REDTHRESHOLD = 0.37;
        const double BLUETHRESHOLD = 0.3;
        const double GREENTHRESHOLD = 0.5;
        const double YELLOWREDTHRESHOLD = 0.3;
        std::string startingColour;
        bool onStartingColour;
        bool m_active;
};

#endif