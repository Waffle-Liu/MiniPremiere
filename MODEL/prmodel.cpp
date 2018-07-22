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
		index_error_notify();
		return;
	}
	videoList[index]->play();
}

void PrModel::removeVideo(int index)
{
	if (index == 6) {
		videoList.clear();
		return;
	} else if (index >= videoNum) {
		index_error_notify();
		return;
	}

	videoList.erase(videoList.begin() + index);
}


void PrModel::setEditIndex(int index)
{
	if (index >= videoNum) {
		index_error_notify();
		return;
	}

	curEditIndex = index;
}


void PrModel::set_index_error_notification(shared_ptr<Notification> ntf)
{
	index_error_notification = ntf;
}

void PrModel::index_error_notify()
{
	index_error_notification->exec();
}
