#include "prmodel.h"

PrModel::PrModel()
{
	videoNum = 0;
	curEditIndex = NIL;
}

PrModel::~PrModel()
{
}

void PrModel::addVideo(const string &video_path)
{
	shared_ptr<Video> video(new Video(video_path));
	videoList.push_back(video);
	videoNum++;
}

void PrModel::playVideo(int index)
{
	if (index >= videoNum) {
		info_notify("No video");
		return;
	}
	videoList[index]->play();
}

void PrModel::removeVideo(int index)
{
	if (index == 6) {
		videoList.clear();
		videoNum = 0;
		return;
	} else if (index >= videoNum) {
		info_notify("No video");
		return;
	}

	videoList.erase(videoList.begin() + index);
	videoNum--;
}

void PrModel::changespeedVideo(double rate)
{
	videoList[curEditIndex]->changeSpeed(rate);
}

void PrModel::cutVideo(int start_frame, int end_frame)
{
	videoList[curEditIndex]->cut(start_frame, end_frame);
	info_notify("Cut success!");
}


void PrModel::setEditIndex(int index)
{
	if (index >= videoNum) {
		info_notify("No video!");
		return;
	}

	curEditIndex = index;
	edit_enable_notify();
}


void PrModel::set_index_error_notification(shared_ptr<Notification> ntf)
{
	info_notification = ntf;
}

void PrModel::info_notify(const string& info)
{
	info_notification->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(info))));
	info_notification->exec();
}


void PrModel::set_edit_enable_notification(shared_ptr<Notification> ntf)
{
	edit_enable_notification = ntf;
}

void PrModel::edit_enable_notify()
{
	edit_enable_notification->exec();
}
