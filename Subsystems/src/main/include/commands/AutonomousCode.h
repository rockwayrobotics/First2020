#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "RobotContainer.h"

class Autonomous : public frc2::CommandHelper<frc2::CommandBase, Autonomous> {
    public:
        Autonomous(RobotContainer* cont);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
    private:
        RobotContainer* m_cont;
        bool finished;
};