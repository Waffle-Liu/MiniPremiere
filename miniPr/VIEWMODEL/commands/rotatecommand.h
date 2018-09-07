#ifndef ROTATECOMMAND_H
#define ROTATECOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class RotateCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    RotateCommand(std::shared_ptr<PrViewModel> vm);
    ~RotateCommand();
    virtual void exec();
};

#endif 