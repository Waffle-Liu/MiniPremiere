#include "../commands/playvideocommand.h"


PlayVideoCommand::PlayVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
PlayVideoCommand::~PlayVideoCommand()
{}

void PlayVideoCommand::exec()
{
	std::string path = std::static_pointer_cast<PathParameters, Parameters>(Command::params)->get_path();
    viewmodel->exec_play_video_command(path);
}
