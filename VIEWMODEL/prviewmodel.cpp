#include "../VIEWMODEL/prviewmodel.h"
#include "../commands/addvideocommand.h"
#include "../commands/playvideocommand.h"
#include "../commands/removevideocommand.h"
#include "../commands/selecteditvideocommand.h"
#include "../commands/cutvideocommand.h"
#include "../commands/speedchangecommand.h"
#include "../notification/wrongindexnotification.h"
#include "../notification/showeditvideonotification.h"

using namespace std;

PrViewModel::PrViewModel(){
	add_video_command = static_pointer_cast<Command, AddVideoCommand>(shared_ptr<AddVideoCommand>(new AddVideoCommand(shared_ptr<PrViewModel> (this))));
	play_video_command = static_pointer_cast<Command, PlayVideoCommand>(shared_ptr<PlayVideoCommand>(new PlayVideoCommand(shared_ptr<PrViewModel>(this))));
	remove_video_command = static_pointer_cast<Command, RemoveVideoCommand>(shared_ptr<RemoveVideoCommand>(new RemoveVideoCommand(shared_ptr<PrViewModel>(this))));
	select_edit_video_command = static_pointer_cast<Command, SelectEditVideoCommand>(shared_ptr<SelectEditVideoCommand>(new SelectEditVideoCommand(shared_ptr<PrViewModel>(this))));
	cut_video_command = static_pointer_cast<Command, CutVideoCommand>(shared_ptr<CutVideoCommand>(new CutVideoCommand(shared_ptr<PrViewModel>(this))));
	changespeed_video_command = static_pointer_cast<Command, SpeedChangeCommand>(shared_ptr<SpeedChangeCommand>(new SpeedChangeCommand(shared_ptr<PrViewModel>(this))));

	index_error_notification = static_pointer_cast<Notification, UpdateInfoNotification>(shared_ptr<UpdateInfoNotification>(new UpdateInfoNotification(shared_ptr<PrViewModel>(this))));
	edit_enable_notification = static_pointer_cast<Notification, UpdateEditEnableNotification>(shared_ptr<UpdateEditEnableNotification>(new UpdateEditEnableNotification(shared_ptr<PrViewModel>(this))));
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

shared_ptr<Notification> PrViewModel::get_index_error_notification()
{
	return index_error_notification;
}

shared_ptr<Notification> PrViewModel::get_edit_enable_notification()
{
	return edit_enable_notification;
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
