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

	shared_ptr<Notification> wrong_index_notification;

public:
	PrModel();
	~PrModel();

	void addVideo(const string& video_path);
	void playVideo(int index);

	void wrong_index_notify();
};
