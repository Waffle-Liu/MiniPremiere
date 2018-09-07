#include "cutvideocommand.h"


CutVideoCommand::CutVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
CutVideoCommand::~CutVideoCommand()
{}

void CutVideoCommand::exec()
{
	int start = std::static_pointer_cast<Int2Parameters, Parameters>(Command::params)->getvalue1();
	int end = std::static_pointer_cast<Int2Parameters, Parameters>(Command::params)->getvalue2();
    viewmodel->exec_cut_video_command(start, end);
}