#include "../commands/transmodecommand.h"


TransModeCommand::TransModeCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
TransModeCommand::~TransModeCommand()
{}


void TransModeCommand::exec()
{	
	int index = std::static_pointer_cast<Int2Parameters, Parameters>(Command::params)->getvalue1();
	int mode = std::static_pointer_cast<Int2Parameters, Parameters>(Command::params)->getvalue2();
    viewmodel->exec_trans_mode_command(index, mode);
}