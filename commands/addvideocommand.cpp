#include "Commands/addmediacommand.h"


AddVideoCommmand::AddVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
AddVideoCommmand::~AddVideoCommmand()
{}

void AddVideoCommmand::Exec()
{
	std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->get_path();
    viewmodel->exec_add_video_command(path);
}
