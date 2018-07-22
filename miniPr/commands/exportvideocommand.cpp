#include "../commands/exportvideocommand.h"


ExportVideoCommand::ExportVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
ExportVideoCommand::~ExportVideoCommand()
{}

void ExportVideoCommand::exec()
{	
	std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->getpath();
    viewmodel->exec_export_video_command(path);
}