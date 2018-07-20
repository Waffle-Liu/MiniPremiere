#ifndef LAYOUTCOMMAND_H
#define LAYOUTCOMMAND_H

#include "../../common/etlbase.h"


class PrViewModel;
class layoutCommand: public ICommandBase
{
public:
    layoutCommand(PrViewModel *ptr_PrViewModel);
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();

private:
    PrViewModel *ptr_PrViewModel_;
};

#endif // LAYOUTCOMMAND_H