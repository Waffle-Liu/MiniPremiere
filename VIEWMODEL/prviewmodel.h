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

public:
	PrViewModel();
	void bind(std::shared_ptr<PrModel> model);

	void exec_add_video_command(string path);
	void exec_play_video_command(int index);

	shared_ptr<Command> get_add_video_command();
	shared_ptr<Command> get_play_video_command();
};
