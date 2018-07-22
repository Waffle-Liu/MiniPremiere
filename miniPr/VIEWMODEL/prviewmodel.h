#pragma once

#include "../common/stdafx.h"
#include "../MODEL/prmodel.h"
#include "../common/command.h"
using namespace std;

class Command;

class PrViewModel
{
private:
	shared_ptr<PrModel> model;

	shared_ptr<Command> add_video_command;
	shared_ptr<Command> play_video_command;
	shared_ptr<Command> remove_video_command;
	shared_ptr<Command> cut_video_command;
	shared_ptr<Command> changespeed_video_command;
	shared_ptr<Command> select_edit_video_command;
	shared_ptr<Command> integrate_all_video_command;

	shared_ptr<Notification> update_view_notification;
	shared_ptr<Notification> index_error_notification;
	shared_ptr<Notification> show_edit_window_notification;
	shared_ptr<Notification> edit_enable_notification;

public:
	PrViewModel();
	void bind(shared_ptr<PrModel> model);

	void exec_add_video_command(string path);
	void exec_play_video_command(int index);
	void exec_remove_video_command(int index);
	void exec_select_edit_video_command(int index);
	void exec_cut_video_command(int start_frame, int end_frame);
	void exec_speed_change_command(double rate);
	void exec_integrate_all_video_command();

	shared_ptr<Command> get_add_video_command();
	shared_ptr<Command> get_play_video_command();
	shared_ptr<Command> get_remove_video_command();
	shared_ptr<Command> get_cut_video_command();
	shared_ptr<Command> get_speed_change_command();
	shared_ptr<Command> get_select_edit_video_command();
	shared_ptr

	shared_ptr<Notification> get_index_error_notification();
	shared_ptr<Notification> get_edit_enable_notification();
	void set_update_view_notification(shared_ptr<Notification> ntf);
	void set_show_edit_window_notification(shared_ptr<Notification> ntf);
	void update_view_notified(const string &str);
	void show_edit_window_notified();
};
