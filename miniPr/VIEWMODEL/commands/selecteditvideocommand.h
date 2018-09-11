#ifndef SELECTEDITVIDEOCOMMAND_H
#define SELECTEDITVIDEOCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class SelectEditVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    SelectEditVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~SelectEditVideoCommand();
    virtual void exec();
};

#endif 