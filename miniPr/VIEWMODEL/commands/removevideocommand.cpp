#include "removevideocommand.h"


RemoveVideoCommand::RemoveVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
RemoveVideoCommand::~RemoveVideoCommand()
{}

void RemoveVideoCommand::exec()
{
	int index = std::static_pointer_cast<IntParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_remove_video_command(index);
}