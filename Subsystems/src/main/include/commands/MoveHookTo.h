#pragma once


#include "subsystems/HookSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class MoveHookTo : public frc2::CommandHelper<frc2::CommandBase, MoveHookTo> {
    public:
        MoveHookTo(HookSubsystem* hook, double height);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        HookSubsystem* m_hook;
        double m_pow;
        double m_target;
        bool m_finished;
        int timeout;
};