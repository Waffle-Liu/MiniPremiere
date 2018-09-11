#ifndef MIRRORCOMMAND_H
#define MIRRORCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class MirrorCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    MirrorCommand(std::shared_ptr<PrViewModel> vm);
    ~MirrorCommand();
    virtual void exec();
};

#endif 