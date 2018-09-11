#ifndef EXPORTVIDEOCOMMAND_H
#define EXPORTVIDEOCOMMAND_H

#include "../../common/command.h"
#include "../prviewmodel.h"
#include <string>

class ExportVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    ExportVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~ExportVideoCommand();
    virtual void exec();
};

#endif 