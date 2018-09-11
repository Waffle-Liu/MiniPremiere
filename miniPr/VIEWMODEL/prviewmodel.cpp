#include "../VIEWMODEL/prviewmodel.h"

#include "../commands/addvideocommand.h"
#include "../commands/playvideocommand.h"
#include "../commands/removevideocommand.h"
#include "../commands/selecteditvideocommand.h"
#include "../commands/cutvideocommand.h"
#include "../commands/speedchangecommand.h"
#include "../commands/integrateallvideocommand.h"
#include "../commands/addsubtitlecommand.h"
#include "../commands/addstickercommand.h"
#include "../commands/mirrorcommand.h"
#include "../commands/rotatecommand.h"
#include "../commands/addfiltercommand.h"
#include "../commands/funnycommand.h"
#include "../commands/exportvideocommand.h"
#include "../commands/transmodecommand.h"

#include "../notification/wrongindexnotification.h"
#include "../notification/showeditvideonotification.h"
#include "../notification/showintegratewindownotification.h"

using namespace std;

PrViewModel::PrViewModel(){
	add_video_command = static_pointer_cast<Command, AddVideoCommand>(shared_ptr<AddVideoCommand>(new AddVideoCommand(shared_ptr<PrViewModel> (this))));
	play_video_command = static_pointer_cast<Command, PlayVideoCommand>(shared_ptr<PlayVideoCommand>(new PlayVideoCommand(shared_ptr<PrViewModel>(this))));
	remove_video_command = static_pointer_cast<Command, RemoveVideoCommand>(shared_ptr<RemoveVideoCommand>(new RemoveVideoCommand(shared_ptr<PrViewModel>(this))));
	select_edit_video_command = static_pointer_cast<Command, SelectEditVideoCommand>(shared_ptr<SelectEditVideoCommand>(new SelectEditVideoCommand(shared_ptr<PrViewModel>(this))));
	cut_video_command = static_pointer_cast<Command, CutVideoCommand>(shared_ptr<CutVideoCommand>(new CutVideoCommand(shared_ptr<PrViewModel>(this))));
	changespeed_video_command = static_pointer_cast<Command, SpeedChangeCommand>(shared_ptr<SpeedChangeCommand>(new SpeedChangeCommand(shared_ptr<PrViewModel>(this))));
	integrate_all_video_command = static_pointer_cast<Command, IntegrateAllVideoCommand>(shared_ptr<IntegrateAllVideoCommand>(new IntegrateAllVideoCommand(shared_ptr<PrViewModel>(this))));
	add_subtitle_command = static_pointer_cast<Command, AddSubtitleCommand>(shared_ptr<AddSubtitleCommand>(new AddSubtitleCommand(shared_ptr<PrViewModel>(this))));
	add_sticker_command = static_pointer_cast<Command, AddStickerCommand>(shared_ptr<AddStickerCommand>(new AddStickerCommand(shared_ptr<PrViewModel>(this))));
	mirror_command = static_pointer_cast<Command, MirrorCommand>(shared_ptr<MirrorCommand>(new MirrorCommand(shared_ptr<PrViewModel>(this))));
	rotate_command = static_pointer_cast<Command, RotateCommand>(shared_ptr<RotateCommand>(new RotateCommand(shared_ptr<PrViewModel>(this))));
	add_filter_command = static_pointer_cast<Command, AddFilterCommand>(shared_ptr<AddFilterCommand>(new AddFilterCommand(shared_ptr<PrViewModel>(this))));
	funny_command = static_pointer_cast<Command, FunnyCommand>(shared_ptr<FunnyCommand>(new FunnyCommand(shared_ptr<PrViewModel>(this))));
	export_video_command = static_pointer_cast<Command, ExportVideoCommand>(shared_ptr<ExportVideoCommand>(new ExportVideoCommand(shared_ptr<PrViewModel> (this))));
	trans_mode_command = static_pointer_cast<Command, TransModeCommand>(shared_ptr<TransModeCommand>(new TransModeCommand(shared_ptr<PrViewModel>(this))));

	index_error_notification = static_pointer_cast<Notification, UpdateInfoNotification>(shared_ptr<UpdateInfoNotification>(new UpdateInfoNotification(shared_ptr<PrViewModel>(this))));
	edit_enable_notification = static_pointer_cast<Notification, UpdateEditEnableNotification>(shared_ptr<UpdateEditEnableNotification>(new UpdateEditEnableNotification(shared_ptr<PrViewModel>(this))));
	integrate_complete_notification = static_pointer_cast<Notification, UpdateIntegrateCompleteNotification>(shared_ptr<UpdateIntegrateCompleteNotification>(new UpdateIntegrateCompleteNotification(shared_ptr<PrViewModel>(this))));
}

void PrViewModel::bind(shared_ptr<PrModel> model)
{
	this->model = model;
}

void PrViewModel::exec_add_video_command(std::string path)
{
	model->addVideo(path);
}

void PrViewModel::exec_play_video_command(int index)
{
	model->playVideo(index);
}

void PrViewModel::exec_remove_video_command(int index)
{
	model->removeVideo(index);
}

void PrViewModel::exec_select_edit_video_command(int index)
{
	model->setEditIndex(index);
}

void PrViewModel::exec_cut_video_command(int start_frame, int end_frame)
{
	model->cutVideo(start_frame, end_frame);
}

void PrViewModel::exec_speed_change_command(double rate)
{
	model->changespeedVideo(rate);
}

void PrViewModel::exec_integrate_all_video_command()
{
	model->integrateAllVideo();
}

void PrViewModel::exec_add_subtitle_command(const string &text, int start_frame, int end_frame, double pos_x, double pos_y, double color_r, double color_g, double color_b, double size, bool isbold)
{
	model->addSubtitle(text, start_frame, end_frame, pos_x, pos_y, color_r, color_g, color_b, size, isbold);
}

void PrViewModel::exec_add_sticker_command(const string &img_path, int start_frame, int end_frame, double pos_x, double pos_y)
{
	model->addSticker(img_path, start_frame, end_frame, pos_x, pos_y);
}

void PrViewModel::exec_mirror_command(int start_frame, int end_frame, int mode)
{
	if (mode == -1) {
		return;
	}
	model->addFilter(start_frame, end_frame, mode);
}

void PrViewModel::exec_rotate_command(int start_frame, int end_frame, int mode)
{
	if (mode == -1) {
		return;
	}
	model->addFilter(start_frame, end_frame, mode);
}

void PrViewModel::exec_add_filter_command(int start_frame, int end_frame, int mode)
{
	if (mode == -1) {
		return;
	}
	model->addFilter(start_frame, end_frame, mode);
}

void PrViewModel::exec_funny_command(int start_frame, int end_frame, int mode)
{
	if (mode == -1) {
		return;
	}
	model->addFilter(start_frame, end_frame, mode);
}

void PrViewModel::exec_export_video_command(const string &video_path)
{
	model->exportVideo(video_path);
}

void PrViewModel::exec_trans_mode_command(int mode)
{
	model->setLinkMode(mode);
}

/*=============================================================================*/

shared_ptr<Command> PrViewModel::get_add_video_command()
{
	return add_video_command;
}

shared_ptr<Command> PrViewModel::get_play_video_command()
{
	return play_video_command;
}

shared_ptr<Command> PrViewModel::get_remove_video_command()
{
	return remove_video_command;
}

shared_ptr<Command> PrViewModel::get_cut_video_command()
{
	return cut_video_command;
}

shared_ptr<Command> PrViewModel::get_speed_change_command()
{
	return changespeed_video_command;
}

shared_ptr<Command> PrViewModel::get_select_edit_video_command()
{
	return select_edit_video_command;
}

shared_ptr<Command> PrViewModel::get_integrate_all_video_command()
{
	return integrate_all_video_command;
}


shared_ptr<Command> PrViewModel::get_add_subtitle_command()
{
	return add_subtitle_command;
}

shared_ptr<Command> PrViewModel::get_add_sticker_command()
{
	return add_sticker_command;
}

shared_ptr<Command> PrViewModel::get_mirror_command()
{
	return mirror_command;
}

shared_ptr<Command> PrViewModel::get_rotate_command()
{
	return rotate_command;
}

shared_ptr<Command> PrViewModel::get_add_filter_command()
{
	return add_filter_command;
}

shared_ptr<Command> PrViewModel::get_funny_command()
{
	return funny_command;
}

shared_ptr<Command> PrViewModel::get_export_video_command()
{
	return export_video_command;
}

shared_ptr<Command> PrViewModel::get_trans_mode_command()
{
	return trans_mode_command;
}

/*============================================================================*/

shared_ptr<Notification> PrViewModel::get_index_error_notification()
{
	return index_error_notification;
}

shared_ptr<Notification> PrViewModel::get_edit_enable_notification()
{
	return edit_enable_notification;
}

shared_ptr<Notification> PrViewModel::get_integrate_complete_notification()
{
	return integrate_complete_notification;
}

void PrViewModel::set_update_view_notification(shared_ptr<Notification> ntf)
{
	update_view_notification = ntf;
}

void PrViewModel::update_view_notified(const string &str)
{
	update_view_notification->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(str))));
	update_view_notification->exec();
}

void PrViewModel::set_show_edit_window_notification(shared_ptr<Notification> ntf)
{
	show_edit_window_notification = ntf;
}

void PrViewModel::show_edit_window_notified()
{
	show_edit_window_notification->exec();
}

void PrViewModel::set_show_integrate_window_notification(shared_ptr<Notification> ntf)
{
	show_integrate_window_notification = ntf;
}

void PrViewModel::show_integrate_window_notified()
{
	show_integrate_window_notification->exec();
}
