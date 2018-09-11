#include "../commands/speedchangecommand.h"


SpeedChangeCommand::SpeedChangeCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
SpeedChangeCommand::~SpeedChangeCommand()
{}

void SpeedChangeCommand::exec()
{
	double rate = std::static_pointer_cast<DoubleParameters, Parameters>(Command::params)->getvalue();
    viewmodel->exec_speed_change_command(rate);
}