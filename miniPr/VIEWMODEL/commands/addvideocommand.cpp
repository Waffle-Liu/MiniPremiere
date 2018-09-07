#include "addvideocommand.h"


AddVideoCommand::AddVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
AddVideoCommand::~AddVideoCommand()
{}

void AddVideoCommand::exec()
{
	std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->get_path();
    viewmodel->exec_add_video_command(path);
}
