#include "prviewmodel.h"

PrViewModel::PrViewModel(){

}

void PrViewModel::setPrModel(std::shared_ptr<PrModel> sp_PrModel){
    sp_PrModel_ = sp_PrModel;
}


void PrViewModel::Exec_layout_command(int level){
    sp_PrModel_->newLayout(level);
}

void PrViewModel::Exec_mouseMove_command(int row, int col){
    sp_PrModel_->mouseMoveChange(row,col);
}