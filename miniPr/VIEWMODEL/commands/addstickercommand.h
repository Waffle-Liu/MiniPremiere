#ifndef ADDSTICKERCOMMAND_H
#define ADDSTICKERCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class AddStickerCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    AddStickerCommand(std::shared_ptr<PrViewModel> vm);
    ~AddStickerCommand();
    virtual void exec();
};

#endif 