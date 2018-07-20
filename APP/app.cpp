#include <QApplication>
#include "app.h"
miniPrAPP::miniPrAPP(){}
miniPrAPP::~miniPrAPP(){}
void miniPrAPP::run()
{
    model = std::make_shared<PrModel>();
    viewmodel = std::make_shared<PrViewModel>();

    viewmodel->setSWModel(model);

}

mainWindow* miniPrApp::getMainWindow()
{
    return &_mainWindow;
}

editWindow* miniPrApp::getEditWindow()
{
    return &_editWindow;
}

intergratedWindow* miniPrApp::getIntergratedWindow(){
    return & _intergratedWindow;
}
