#include <QApplication>
#include "app.h"
miniPrAPP::miniPrAPP(){

	model = std::make_shared<PrModel>();
	viewmodel = std::make_shared<PrViewModel>();

	viewmodel->bind(model);

	_mainWindow.setAddVideoCommand(viewmodel->get_add_video_command());
	_mainWindow.setPlayVideoCommand(viewmodel->get_play_video_command());
	_mainWindow.setRemoveVideoCommand(viewmodel->get_remove_video_command());

	viewmodel->set_update_view_notification(_mainWindow.get_update_mainwindow_notification());
	model->set_index_error_notification(viewmodel->get_index_error_notification());
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
