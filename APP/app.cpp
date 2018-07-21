#include <QApplication>
#include "app.h"
miniPrAPP::miniPrAPP(){

	model = std::make_shared<PrModel>();
	viewmodel = std::make_shared<PrViewModel>();

	viewmodel->bind(model);

	_mainWindow.setAddVideoCommand(viewmodel->get_add_video_command());
	_mainWindow.setPlayVideoCommand(viewdmodel->get_play_video_command());
}
miniPrAPP::~miniPrAPP(){}
void miniPrAPP::run()
{
	_mainWindow.show();
}

MainWindow* miniPrAPP::getMainWindow()
{
    return &_mainWindow;
}
/*
Dialog_edit* miniPrAPP::getEditWindow()
{
    return &_editWindow;
}
*/
/*
Dialog_IntegratedVideo* miniPrAPP::getIntegratedWindow(){
    return & _integratedWindow;
}
*/
