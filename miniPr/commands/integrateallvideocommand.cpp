#include "../commands/integrateallvideocommand.h"

IntegrateAllVideoCommand::IntegrateAllVideoCommandCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
IntegrateAllVideoCommandCommand::~IntegrateAllVideoCommand()
{}

void IntegrateAllVideoCommand::exec()
{
    viewmodel->exec_integrate_all_video_command();
}