#ifndef SHOWINTEGRATEWINDOWCOMMAND_H
#define SHOWINTEGRATEWINDOWCOMMAND_H

#include "../common/command.h"
#include <string>

class miniPrAPP;
class ShowIntegrateWindowCommand: public Command
{
private:
    miniPrAPP *ptrAPP;
public:
    ShowIntegrateWindowCommand(miniPrAPP *pa);
    ~ShowIntegrateWindowCommand();
    virtual void exec();
};

#endif 