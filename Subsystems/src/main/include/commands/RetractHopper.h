#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/HopperSubsystem.h"

class RetractHopper : public frc2::CommandHelper<frc2::CommandBase, RetractHopper> {
    public:
        RetractHopper(HopperSubsystem* hopper);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        HopperSubsystem* m_hopper;
        int m_cycleCount;
        int m_toggleCount;
        bool m_off;
        bool m_finished = true;
};