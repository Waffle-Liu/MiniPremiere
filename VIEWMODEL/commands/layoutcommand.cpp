#include "layoutcommand.h"
#include "../prviewmodel.h"

layoutCommand::layoutCommand(PrViewModel *ptr_PrViewModel)
{
    ptr_PrViewModel_ = ptr_PrViewModel;
}

void layoutCommand::SetParameter(const _new_any_space_::any& param)
{
    PrLevel = _new_any_space_::any_cast<int>(param);
}

void layoutCommand::Exec()
{
    ptr_PrViewModel_->Exec_layout_command(PrLevel);
    ptr_PrViewModel_->Fire_OnCommandComplete("layoutCommand", true);
}