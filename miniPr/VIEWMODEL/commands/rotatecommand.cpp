#include "../commands/rotatecommand.h"


RotateCommand::RotateCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
RotateCommand::~RotateCommand()
{}

void RotateCommand::exec()
{	
	int start = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getendframe();
	int mode = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getmode();

    viewmodel->exec_rotate_command(start, end, mode);
}