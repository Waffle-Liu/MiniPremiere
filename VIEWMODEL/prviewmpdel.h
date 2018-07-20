#ifndef PRVIEWMODEL_H
#define PRVIEWMODEL_H

#include "../MODEL/prmodel.h"
#include "../common/etlbase.h"


class PrViewModel:public Proxy_PropertyNotification<PrViewModel>,
        public Proxy_CommandNotification<PrViewModel>
{
public:
    PrViewModel();
    ~PrViewModel(){}
    void setPrModel(std::shared_ptr<SWModel> sp_SWModel);

    void Exec_layout_command(int level);
    void Exec_mouseMove_command(int row, int col);

private:
    std::shared_ptr<PrModel> sp_PrModel_;

};

#endif // SWVIEWMODEL_H