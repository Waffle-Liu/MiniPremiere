#include "addfiltercommand.h"


AddFilterCommand::AddFilterCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
AddFilterCommand::~AddFilterCommand()
{}


void AddFilterCommand::exec()
{	
	int start = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getendframe();
	int mode = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getmode();

    viewmodel->exec_add_filter_command(start, end, mode);
}