#include "mirrorcommand.h"


MirrorCommand::MirrorCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
MirrorCommand::~MirrorCommand()
{}

void MirrorCommand::exec()
{	
	int start = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getendframe();
	int mode = std::static_pointer_cast<FilterParameters, Parameters>(Command::params)->getmode();

    viewmodel->exec_mirror_command(start, end, mode);
}