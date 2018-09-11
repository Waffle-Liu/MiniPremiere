#ifndef SPEEDCHANGECOMMAND_H
#define SPEEDCHANGECOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class SpeedChangeCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    SpeedChangeCommand(std::shared_ptr<PrViewModel> vm);
    ~SpeedChangeCommand();
    virtual void exec();
};

#endif 