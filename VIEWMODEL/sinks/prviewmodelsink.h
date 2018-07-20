#ifndef PRVIEWMODELSINK_H
#define PRVIEWMODELSINK_H

#include "../../common/etlbase.h"

class PrViewModel;
class PrViewModelSink: public IPropertyNotification
{
public:
    PrViewModelSink(SWViewModel *ptr);
    virtual void OnPropertyChanged(const std::string& str);
private:
    PrViewModel *ptr_PrViewModel;
};

#endif // PRVIEWMODELSINK_H