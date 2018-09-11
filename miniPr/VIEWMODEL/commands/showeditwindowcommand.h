#ifndef SHOWEDITWINDOWCOMMAND_H
#define SHOWEDITWINDOWCOMMAND_H

#include "../../common/command.h"
#include <string>

class miniPrAPP;
class ShowEditWindowCommand: public Command
{
private:
    miniPrAPP *ptrAPP;
public:
    ShowEditWindowCommand(miniPrAPP *pa);
    ~ShowEditWindowCommand();
    virtual void exec();
};

#endif 