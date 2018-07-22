#pragma once

#include "stdafx.h"
#include "windowSize.h"
#include "FilterFunction.h"
using namespace std;
using namespace cv;

typedef vector<shared_ptr<Mat>> VideoFrames;
class Video
{
private:
	int fCnt;  // frames count
	double fps;  // frames per second
	windowSize wSize;  // window size
	VideoFrames frames;  // frames list

public:
	Video();
	Video(const string &video_path);  // Video(video_path): Capture the video at the destination path.
	~Video();

	bool capture(const string &video_path);  // this->capture(video_path): Capture the video at the destination path.
	bool writer(const string &video_path);
	void play();  // this->play(): Play the video.
	bool cut(int start_frame, int end_frame);
	bool link(shared_ptr<Video> next_video, int mode = -1);
	bool changeSpeed(double rate);
	bool addFilter(int mode, int start_frame, int end_frame);
	bool addSubtitle(const string &text, int start_frame, int end_frame, double x, double y, double r, double g, double b, double fontSize, bool isbold);
	bool addSticker(const string &image_path, int start_frame, int end_frame, double pos_x, double pos_y);
};
