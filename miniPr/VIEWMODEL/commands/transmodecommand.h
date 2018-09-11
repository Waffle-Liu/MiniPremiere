#ifndef TRANSMODECOMMAND_H
#define TRANSMODECOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class TransModeCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    TransModeCommand(std::shared_ptr<PrViewModel> vm);
    ~TransModeCommand();
    virtual void exec();
};

#endif 