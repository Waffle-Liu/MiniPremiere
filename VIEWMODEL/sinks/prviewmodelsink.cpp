#include "prviewmodelsink.h"
#include "../prviewmodel.h"

PrViewModelSink::PrViewModelSink(PrViewModel *ptr)
{
    ptr_PrViewModel = ptr;
}

void PrViewModelSink::OnPropertyChanged(const std::string& str){
    ptr_PrViewModel->Fire_OnPropertyChanged(str);
}