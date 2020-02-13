#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/HopperSubsystem.h"

class ToggleHopper : public frc2::CommandHelper<frc2::CommandBase, ToggleHopper> {
    public:
        ToggleHopper(HopperSubsystem* hopper);
        void Initialize();
        bool IsFinished();
    private:
        HopperSubsystem* m_hopper;
        bool m_dumped;
        bool m_finished;
};