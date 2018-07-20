#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "../common/etlbase.h"

class PrModel: public Proxy_PropertyNotification<PrModel>, public Proxy_CommandNotification<PrModel>
{
public:
    PrModel();
    ~PrModel(){}
    std::shared_ptr<SWMatrix> getSWMatrix();
    void newLayout(int level);
    void mouseMoveChange(int curRow, int curCol);
    void changePointColor(int curRow, int curCol);
private:
    std::shared_ptr<SWMatrix> sp_SWMatrix;
};

#endif 