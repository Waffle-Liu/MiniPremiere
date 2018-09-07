#include "showintegratewindowcommand.h"
#include "../../APP/app.h"

ShowIntegrateWindowCommand::ShowIntegrateWindowCommand(miniPrAPP *ptrAPP):ptrAPP(ptrAPP)
{
}
ShowIntegrateWindowCommand::~ShowIntegrateWindowCommand()
{}

void ShowIntegrateWindowCommand::exec()
{
	(ptrAPP->getIntegratedWindow())->show();
}