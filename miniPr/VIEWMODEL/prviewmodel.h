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
	shared_ptr<Command> add_subtitle_command;
	shared_ptr<Command> add_sticker_command;
	shared_ptr<Command> mirror_command;
	shared_ptr<Command> rotate_command;
	shared_ptr<Command> add_filter_command;
	shared_ptr<Command> funny_command;
	shared_ptr<Command> export_video_command;
	shared_ptr<Command> trans_mode_command;

	shared_ptr<Notification> update_view_notification;
	shared_ptr<Notification> index_error_notification;
	shared_ptr<Notification> show_edit_window_notification;
	shared_ptr<Notification> edit_enable_notification;
	shared_ptr<Notification> show_integrate_window_notification;
	shared_ptr<Notification> integrate_complete_notification;

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
	void exec_add_subtitle_command(const string &text, int start_frame, int end_frame, double pos_x, double pos_y, double color_r, double color_g, double color_b, double size, bool isbold);
	void exec_add_sticker_command(const string &img_path, int start_frame, int end_frame, double pos_x, double pos_y);
	void exec_mirror_command(int start_frame, int end_frame, int mode);
	void exec_rotate_command(int start_frame, int end_frame, int mode);
	void exec_add_filter_command(int start_frame, int end_frame, int mode);
	void exec_funny_command(int start_frame, int end_frame, int mode);
	void exec_export_video_command(const string &video_path);
	void exec_trans_mode_command(int mode);


	shared_ptr<Command> get_add_video_command();
	shared_ptr<Command> get_play_video_command();
	shared_ptr<Command> get_remove_video_command();
	shared_ptr<Command> get_cut_video_command();
	shared_ptr<Command> get_speed_change_command();
	shared_ptr<Command> get_select_edit_video_command();
	shared_ptr<Command> get_integrate_all_video_command();
	shared_ptr<Command> get_add_subtitle_command();
	shared_ptr<Command> get_add_sticker_command();
	shared_ptr<Command> get_mirror_command();
	shared_ptr<Command> get_rotate_command();
	shared_ptr<Command> get_add_filter_command();
	shared_ptr<Command> get_funny_command();
	shared_ptr<Command> get_export_video_command();
	shared_ptr<Command> get_trans_mode_command();

	shared_ptr<Notification> get_index_error_notification();
	shared_ptr<Notification> get_edit_enable_notification();
	shared_ptr<Notification> get_integrate_complete_notification();

	void set_update_view_notification(shared_ptr<Notification> ntf);
	void set_show_edit_window_notification(shared_ptr<Notification> ntf);
	void set_show_integrate_window_notification(shared_ptr<Notification> ntf);

	void update_view_notified(const string &str);
	void show_edit_window_notified();
	void show_integrate_window_notified();
};
