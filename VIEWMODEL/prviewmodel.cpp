#include "../VIEWMODEL/prviewmodel.h"
#include "../commands/addvideocommand.h"

PrViewModel::PrViewModel(){
	add_video_command = std::static_pointer_cast<Command, AddVideoCommand>(std::shared_ptr<AddVideoCommand>(new AddVideoCommand(std::shared_ptr<PrViewModel> (this))));
}

void PrViewModel::exec_add_video_command(std::string path) {
	model->addVideo(path);
}

void PrViewModel::bind(shared_ptr<PrModel> model) {
	this->model = model;
}

shared_ptr<Command> PrViewModel::get_add_video_command() {
	return add_video_command;
}