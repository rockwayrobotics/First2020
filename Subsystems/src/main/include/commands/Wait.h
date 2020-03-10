#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Wait : public frc2::CommandHelper<frc2::CommandBase, Wait> {
    public:
        Wait(int cycles);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;
    private:
        int m_count;
        int m_target;
};