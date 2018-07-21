#ifndef ADDVEDIOCOMMAND_H
#define ADDVEDIOCOMMAND_H

#include "command.h"
#include "VIEWMODEL/prviewmodel.h"

class miniPrAPP;
class AddVideoCommand: public Command
{
private:
    miniPrAPP *ptrApp;
public:
    AddVedioCommand(miniPrAPP *ptr_App);
    ~AddVedioCommand();
    virtual void SetParameter(const _new_any_space_::any& param);
    virtual void Exec();
};

#endif // ADDMEDIACOMMAND_H
