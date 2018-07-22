#include "../commands/showeditwindowcommand.h"
#include "app.h"

ShowEditWindowCommand::ShowEditWindowCommand(miniPrAPP *ptrAPP):ptrAPP(pa)
{
}
ShowEditWindowCommand::~ShowEditWindowCommand()
{}

void ShowEditWindowCommand::exec()
{
	(ptrAPP->getEditWindow())->show();
}