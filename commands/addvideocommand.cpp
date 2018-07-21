#include "addmediacommand.h"
#include "../app.h"


AddVedioCommmand::AddVedioCommand(miniPrAPP *ptr_App)
{
    ptrApp = ptr_App;
}
AddVedioCommmand::~AddVedioCommmand()
{}
void AddVedioCommmand::SetParameter(const _new_any_space_::any& param)
{

}
void AddVedioCommmand::Exec()
{
    (ptrApp->getFormWindow())->close();
    (ptrApp->getGameWindow())->show();
}
