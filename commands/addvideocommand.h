#ifndef ADDVEDIO_H
#define ADDVEDIO_H

#include "../../common/etlbase.h"

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

#endif // ADDMEDIA_H
