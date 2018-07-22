#include "../commands/transmodecommand.h"


TransModeCommand::TransModeCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
TransModeCommand::~TransModeCommand()
{}


void TransModeCommand::exec()
{	
	int mode = std::static_pointer_cast<IntParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_trans_mode_command(mode);
}