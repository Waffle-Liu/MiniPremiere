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
	shared_ptr<Notification> integrate_complete_notification;

public:
	PrModel();
	~PrModel();

	void addVideo(const string& video_path);
	void playVideo(int index);
	void removeVideo(int index);
	void changespeedVideo(double rate);
	void cutVideo(int start_frame, int end_frame);
	void integrateAllVideo();
	void addSubtitle(const string &text, int start_frame, int end_frame, double pos_x, double pos_y, double color_r, double color_g, double color_b, double size, bool isbold);
	void setEditIndex(int index);
	void addSticker(const string &img_path, int start_frame, int end_frame, double pos_x, double pos_y);
	void addFilter(int start_frame, int end_frame, int mode);

	void set_index_error_notification(shared_ptr<Notification> ntf);
	void set_edit_enable_notification(shared_ptr<Notification> ntf);
	void set_integrate_complete_notification(shared_ptr<Notification> ntf);

	void info_notify(const string& info);
	void edit_enable_notify();
	void integrate_complete_notify();

};
