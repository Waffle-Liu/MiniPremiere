#pragma once

#include "..\common\stdafx.h"
#include "..\common\Video.h"
#include "..\notification\notification.h"

#define NIL -1

using namespace std;
using namespace cv;

class PrModel
{
private:
	int videoNum;
	vector<shared_ptr<Video>> videoList;
	int curEditIndex;

	shared_ptr<Notification> info_notification;
	shared_ptr<Notification> edit_enable_notification;

public:
	PrModel();
	~PrModel();

	void addVideo(const string& video_path);
	void playVideo(int index);
	void removeVideo(int index);
	void changespeedVideo(double rate);
	void cutVideo(int start_frame, int end_frame);

	void setEditIndex(int index);


	void set_index_error_notification(shared_ptr<Notification> ntf);
	void set_edit_enable_notification(shared_ptr<Notification> ntf);
	void info_notify(const string& info);
	void edit_enable_notify();

};
