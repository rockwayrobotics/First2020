#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>

#include "subsystems/DrivebaseSubsystem.h"

class ScaleDrive : public frc2::CommandHelper<frc2::CommandBase, ScaleDrive> {
    public:
        ScaleDrive(DrivebaseSubsystem* drivebase, double scale);
        void Initialize();
        bool IsFinished();
    private:
        DrivebaseSubsystem* m_drivebase;
        double m_scale;
        bool m_finished;
};