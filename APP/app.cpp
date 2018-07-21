#include <QApplication>
#include "app.h"
miniPrAPP::miniPrAPP(){}
miniPrAPP::~miniPrAPP(){}
void miniPrAPP::run()
{
    model = std::make_shared<PrModel>();
    viewmodel = std::make_shared<PrViewModel>();

    viewmodel->setSWModel(model);

    _mainWindow.setAddMediaCommand(std::static_pointer_cast<ICommandBase>(this->_spAddMediaCommand));


    _spAddMediaCommand = std::make_shared<AddMediaCommand>(this);

}

mainWindow* miniPrApp::getMainWindow()
{
    return &_mainWindow;
}

Dialog_edit* miniPrApp::getEditWindow()
{
    return &_editWindow;
}

Dialog_IntergratedVideo* miniPrApp::getIntergratedWindow(){
    return & _intergratedWindow;
}
