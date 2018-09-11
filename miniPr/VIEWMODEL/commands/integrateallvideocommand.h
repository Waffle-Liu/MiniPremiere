#ifndef INTEGRATEALLVIDEOCOMMAND_H
#define INTEGRATEALLVIDEOCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class IntegrateAllVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    IntegrateAllVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~IntegrateAllVideoCommand();
    virtual void exec();
};

#endif 