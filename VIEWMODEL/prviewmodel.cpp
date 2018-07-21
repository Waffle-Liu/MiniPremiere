#include "../VIEWMODEL/prviewmodel.h"
#include "../commands/addvideocommand.h"
#include "../commands/playvideocommand.h"
#include "../notification/wrongindexnotification.h"

PrViewModel::PrViewModel(){
	add_video_command = std::static_pointer_cast<Command, AddVideoCommand>(std::shared_ptr<AddVideoCommand>(new AddVideoCommand(std::shared_ptr<PrViewModel> (this))));
	play_video_command = static_pointer_cast<Command, PlayVideoCommand>(shared_ptr<PlayVideoCommand>(new PlayVideoCommand(shared_ptr<PrViewModel>(this))));
	index_error_notification = std::static_pointer_cast<Notification, UpdateIndexErrorNotification>
		(std::shared_ptr<UpdateIndexErrorNotification>(new UpdateIndexErrorNotification(std::shared_ptr<PrViewModel>(this))));
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

shared_ptr<Command> PrViewModel::get_add_video_command() {
	return add_video_command;
}

shared_ptr<Command> PrViewModel::get_play_video_command()
{
	return play_video_command;
}

shared_ptr<Notification> PrViewModel::get_index_error_notification()
{
	return index_error_notification;
}

void PrViewModel::set_update_view_notification(shared_ptr<Notification> ntf)
{
	update_view_notification = ntf;
}

void PrViewModel::index_error_notified()
{
	update_view_notification->exec();
}
