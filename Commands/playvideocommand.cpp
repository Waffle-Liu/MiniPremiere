#include "../commands/playvideocommand.h"


PlayVideoCommand::PlayVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
PlayVideoCommand::~PlayVideoCommand()
{}

void PlayVideoCommand::exec()
{
	int index = std::static_pointer_cast<IntParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_play_video_command(index);
}
