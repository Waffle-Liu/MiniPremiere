#ifndef PLAYVEDIOCOMMAND_H
#define PLAYVEDIOCOMMAND_H

#include "../common/command.h"
#include "../VIEWMODEL/prviewmodel.h"
#include <string>

class PlayVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    PlayVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~PlayVideoCommand();
    virtual void exec();
};

#endif // ADDMEDIACOMMAND_H