#include "funnycommand.h"


FunnyCommand::FunnyCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
FunnyCommand::~FunnyCommand()
{}

void FunnyCommand::exec()
{	
	int start = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getendframe();
	int mode = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getmode();

    viewmodel->exec_funny_command(start, end, mode);
}