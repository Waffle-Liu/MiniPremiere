#include "showeditwindowcommand.h"
#include "../../APP/app.h"

ShowEditWindowCommand::ShowEditWindowCommand(miniPrAPP *ptrAPP):ptrAPP(ptrAPP)
{
}
ShowEditWindowCommand::~ShowEditWindowCommand()
{}

void ShowEditWindowCommand::exec()
{
	(ptrAPP->getEditWindow())->show();
}