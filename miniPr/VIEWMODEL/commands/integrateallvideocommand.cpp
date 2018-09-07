#include "integrateallvideocommand.h"

IntegrateAllVideoCommand::IntegrateAllVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
IntegrateAllVideoCommand::~IntegrateAllVideoCommand()
{}

void IntegrateAllVideoCommand::exec()
{
    viewmodel->exec_integrate_all_video_command();
}