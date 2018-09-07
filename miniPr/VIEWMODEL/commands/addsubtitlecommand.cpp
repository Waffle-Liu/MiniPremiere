#include "addsubtitlecommand.h"


AddSubtitleCommand::AddSubtitleCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
AddSubtitleCommand::~AddSubtitleCommand()
{}

void AddSubtitleCommand::exec()
{	
	std::string text = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->gettext();
	int start = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getendframe();
	double x = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getx();
	double y = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->gety();
	double r = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getr();
	double g = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getg();
	double b = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getb();
	double size = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getsize();
	bool isbold = std::static_pointer_cast<SubtitleParameters, Parameters>(Command::params)->getisbold();
    viewmodel->exec_add_subtitle_command(text, start, end, x, y, r, g, b, size, isbold);
}