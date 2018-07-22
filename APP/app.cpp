#include <QApplication>
#include "app.h"
miniPrAPP::miniPrAPP(){

	model = std::make_shared<PrModel>();
	viewmodel = std::make_shared<PrViewModel>();

	viewmodel->bind(model);

	_mainWindow.setAddVideoCommand(viewmodel->get_add_video_command());
	_mainWindow.setPlayVideoCommand(viewmodel->get_play_video_command());
	_mainWindow.setRemoveVideoCommand(viewmodel->get_remove_video_command());
	_mainWindow.setSelectEditVideoCommand(viewmodel->get_select_edit_video_command());
	_editWindow.setSpeedChangeCommand(viewmodel->get_speed_change_command());

	viewmodel->set_update_view_notification(_mainWindow.get_update_mainwindow_notification());
	model->set_index_error_notification(viewmodel->get_index_error_notification());

	viewmodel->set_show_edit_window_notification(_mainWindow.get_show_edit_notification());
	model->set_edit_enable_notification(viewmodel->get_edit_enable_notification());

	_spShowEditWindowCommand = std::make_shared<ShowEditWindowCommand>(this);
	_mainWindow.setShowEditWindowCommand(_spShowEditWindowCommand);

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

Dialog_edit* miniPrAPP::getEditWindow()
{
    return &_editWindow;
}

/*
Dialog_IntegratedVideo* miniPrAPP::getIntegratedWindow(){
    return & _integratedWindow;
}
*/
