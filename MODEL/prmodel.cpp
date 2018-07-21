#include "prmodel.h"

PrModel::PrModel()
{
}

PrModel::~PrModel()
{
}

void PrModel::addVideo(const string &video_path)
{
	shared_ptr<Video> video(new Video(video_path));
	videoList.push_back(video);
}

void PrModel::playVideo(int index)
{
	if (index >= videoNum) {
		wrong_index_notify();
	}
	videoList[index]->play();
}

void wrong_index_notify()
{
	wrong_index_notification->exec();
}
