#ifndef ADDVEDIOCOMMAND_H
#define ADDVEDIOCOMMAND_H

#include "command.h"
#include "VIEWMODEL/prviewmodel.h"
#include <string>
#include <memory>
#include <Qdebug>

class AddVideoCommand: public Command
{
private:
    std::shared_ptr<PrViewModel> viewmodel;
public:
    AddVideoCommand(std::shared_ptr<PrViewModel> vm);
    ~AddVideoCommand();
    virtual void Exec();
};

#endif // ADDMEDIACOMMAND_H
