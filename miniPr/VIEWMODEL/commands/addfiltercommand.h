#ifndef ADDFILTERCOMMAND_H
#define ADDFILTERCOMMAND_H

#include "..\..\common/command.h"
#include "..\prviewmodel.h"
#include <string>

class AddFilterCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    AddFilterCommand(std::shared_ptr<PrViewModel> vm);
    ~AddFilterCommand();
    virtual void exec();
};

#endif 