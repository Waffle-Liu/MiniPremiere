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
	_mainWindow.setIntegrateAllVideoCommand(viewmodel->get_integrate_all_video_command());
	_editWindow.setSpeedChangeCommand(viewmodel->get_speed_change_command());
	_editWindow.setCutVideoCommand(viewmodel->get_cut_video_command());
	_integratedWindow.setAddSubtitleCommand(viewmodel->get_add_subtitle_command());
	_integratedWindow.setAddStickerCommand(viewmodel->get_add_sticker_command());
	_integratedWindow.setMirrorCommand(viewmodel->get_mirror_command());
	_integratedWindow.setRotateCommand(viewmodel->get_rotate_command());
	_integratedWindow.setAddFilterCommand(viewmodel->get_add_filter_command());
	_integratedWindow.setFunnyCommand(viewmodel->get_funny_command());
	_integratedWindow.setExportVideoCommand(viewmodel->get_export_video_command());
	_integratedWindow.setPlayVideoCommand(viewmodel->get_play_video_command());

	viewmodel->set_update_view_notification(_mainWindow.get_update_mainwindow_notification());
	model->set_index_error_notification(viewmodel->get_index_error_notification());

	viewmodel->set_show_edit_window_notification(_mainWindow.get_show_edit_notification());
	model->set_edit_enable_notification(viewmodel->get_edit_enable_notification());

	viewmodel->set_show_integrate_window_notification(_mainWindow.get_show_integrate_notification());
	model->set_integrate_complete_notification(viewmodel->get_integrate_complete_notification());


	_spShowEditWindowCommand = std::make_shared<ShowEditWindowCommand>(this);
	_spShowIntegrateWindowCommand = std::make_shared<ShowIntegrateWindowCommand>(this);
	_mainWindow.setShowEditWindowCommand(_spShowEditWindowCommand);
	_mainWindow.setShowIntegrateWindowCommand(_spShowIntegrateWindowCommand);

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

Dialog_IntegratedVideo* miniPrAPP::getIntegratedWindow(){
    return & _integratedWindow;
}
