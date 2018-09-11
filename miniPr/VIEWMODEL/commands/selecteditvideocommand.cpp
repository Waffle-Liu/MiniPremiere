#include "selecteditvideocommand.h"

SelectEditVideoCommand::SelectEditVideoCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
SelectEditVideoCommand::~SelectEditVideoCommand()
{}

void SelectEditVideoCommand::exec()
{
	int index = std::static_pointer_cast<IntParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_select_edit_video_command(index);
}