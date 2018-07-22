#include "../commands/addstickercommand.h"


AddStickerCommand::AddStickerCommand(std::shared_ptr<PrViewModel> vm):viewmodel(vm)
{
}
AddStickerCommand::~AddStickerCommand()
{}

void AddStickerCommand::exec()
{	
	std::string path = std::static_pointer_cast<StickerParameters, Parameters>(Command::params)->getpath();
	int start = std::static_pointer_cast<StickerParameters, Parameters>(Command::params)->getstartframe();
	int end = std::static_pointer_cast<StickerParameters, Parameters>(Command::params)->getendframe();
	double x = std::static_pointer_cast<StickerParameters, Parameters>(Command::params)->getx();
	double y = std::static_pointer_cast<StickerParameters, Parameters>(Command::params)->gety();
    viewmodel->exec_add_sticker_command(path, start, end, x, y);
}