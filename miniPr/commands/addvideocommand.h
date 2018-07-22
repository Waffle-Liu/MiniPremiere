#ifndef ADDVEDIOCOMMAND_H
#define ADDVEDIOCOMMAND_H

#include "../common/command.h"
#include "../VIEWMODEL/prviewmodel.h"
#include <string>

class AddVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    AddVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~AddVideoCommand();
    virtual void exec();
};

#endif // ADDMEDIACOMMAND_H
