#ifndef REMOVEVIDEOCOMMAND_H
#define REMOVEVIDEOCOMMAND_H

#include "../common/command.h"
#include "../VIEWMODEL/prviewmodel.h"
#include <string>

class RemoveVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    RemoveVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~RemoveVideoCommand();
    virtual void exec();
};

#endif 