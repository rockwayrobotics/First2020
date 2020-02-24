#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DrivebaseSubsystem.h"

class Autonomous : public frc2::CommandHelper<frc2::CommandBase, Autonomous> {
    public:
        Autonomous(DrivebaseSubsystem* Drbase);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        DrivebaseSubsystem* m_Drbase;
        bool finished;
};