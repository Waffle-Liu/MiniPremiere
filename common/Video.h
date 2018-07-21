#pragma once

#include "stdafx.h"
#include "windowSize.h"
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
	void play();  // this->play(): Play the video.
};
