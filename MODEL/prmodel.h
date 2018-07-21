#pragma once

#include "..\common\stdafx.h"
#include "..\common\Video.h"
#include "..\notification\notification.h"

using namespace std;
using namespace cv;

class PrModel
{
private:
	int videoNum;
	vector<shared_ptr<Video>> videoList;

	shared_ptr<Notification> index_error_notification;

public:
	PrModel();
	~PrModel();

	void addVideo(const string& video_path);
	void playVideo(int index);

	void set_index_error_notification(shared_ptr<Notification> ntf);
	void index_error_notify();
};
