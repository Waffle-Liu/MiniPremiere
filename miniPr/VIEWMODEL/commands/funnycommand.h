#ifndef FUNNYCOMMAND_H
#define FUNNYCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class FunnyCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    FunnyCommand(std::shared_ptr<PrViewModel> vm);
    ~FunnyCommand();
    virtual void exec();
};

#endif 