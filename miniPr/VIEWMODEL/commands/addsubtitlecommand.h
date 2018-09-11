#ifndef ADDSUBTITLECOMMAND_H
#define ADDSUBTITLECOMMAND_H

#include "../common/command.h"
#include "../VIEWMODEL/prviewmodel.h"
#include <string>

class AddSubtitleCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    AddSubtitleCommand(std::shared_ptr<PrViewModel> vm);
    ~AddSubtitleCommand();
    virtual void exec();
};

#endif 