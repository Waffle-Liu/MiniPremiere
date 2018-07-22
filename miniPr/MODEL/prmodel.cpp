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
	shared_ptr<Video> video(new Video);
	if (video->capture(video_path)) {
		videoList.push_back(video);
		videoNum++;
		info_notify("Add success!");
	} else {
		info_notify("Add failed!");
	}
}

void PrModel::exportVideo(const string& video_path)
{
	videoList[curEditIndex]->writer(video_path);
	info_notify("Export success!");
}

void PrModel::playVideo(int index)
{
	if (index >= videoNum) {
		info_notify("No video!");
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
		info_notify("No video!");
		return;
	}

	videoList.erase(videoList.begin() + index);
	videoNum--;
}

void PrModel::changespeedVideo(double rate)
{
	videoList[curEditIndex]->changeSpeed(rate);
	info_notify("Change speed success!");
}

void PrModel::cutVideo(int start_frame, int end_frame)
{
	if (videoList[curEditIndex]->cut(start_frame, end_frame)) {
		info_notify("Cut success!");
	} else {
		info_notify("Cut failed!");
	}
}

void PrModel::integrateAllVideo()
{
	for (int i = 1; i < videoNum; i++) {
		videoList[0]->link(videoList[1]);
		videoList.erase(videoList.begin() + 1);
	}
	videoNum = 1;
	curEditIndex = 0;
	integrate_complete_notify();
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

void PrModel::addSubtitle(const string &text, int start_frame, int end_frame, double pos_x, double pos_y, double color_r, double color_g, double color_b, double size, bool isbold)
{
	videoList[curEditIndex]->addSubtitle(text, start_frame, end_frame, pos_x, pos_y, color_r, color_g, color_b, size, isbold);
	info_notify("Subtitle added success!");
}

void PrModel::addSticker(const string &img_path, int start_frame, int end_frame, double pos_x, double pos_y)
{
	videoList[curEditIndex]->addSticker(img_path, start_frame, end_frame, pos_x, pos_y);
	info_notify("Sticker added success!");
}

void PrModel::addFilter(int start_frame, int end_frame, int mode)
{
	videoList[curEditIndex]->addFilter(mode, start_frame, end_frame);
	switch (mode)
	{
	case 0:
		info_notify("Mirror success!");
		break;
	case 1:
		info_notify("Rotate success!");
		break;
	case 3:
		info_notify("Adding filter \"FuDiao\" success!");
		break;
	case 4:
		info_notify("Adding filter \"FuDiao\" success!");
		break;
	case 5:
		info_notify("Adding funny filter \"KuoZhang\" success!");
		break;
	case 6:
		info_notify("Adding funny filter \"JiYa\" success!");
		break;
	case 7:
		info_notify("Adding funny filter \"BoLang\" success!");
		break;
	case 12:
		info_notify("Adding filter \"SuMiao\" success!");
		break;
	case 13:
		info_notify("Adding filter \"HuaiJiu\" success!");
		break;
	case 14:
		info_notify("Adding filter \"QiangGuang\" success!");
		break;
	default:
		info_notify("Failed adding filter!");
		break;
	}
}

/*=============================================================================*/

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

void PrModel::set_integrate_complete_notification(shared_ptr<Notification> ntf)
{
	integrate_complete_notification = ntf;
}

void PrModel::edit_enable_notify()
{
	edit_enable_notification->exec();
}

void PrModel::integrate_complete_notify()
{
	integrate_complete_notification->exec();
}
