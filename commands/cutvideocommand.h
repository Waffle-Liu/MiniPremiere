#ifndef CUTVIDEOCOMMAND_H
#define CUTVIDEOCOMMAND_H

#include "../common/command.h"
#include "../VIEWMODEL/prviewmodel.h"
#include <string>

class CutVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    CutVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~CutVideoCommand();
    virtual void exec();
};

#endif 