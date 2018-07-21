#include "stdafx.h"
#include "Video.h"

Video::Video()
{
}

Video::Video(const string & video_path)
{
	this->capture(video_path);
}

Video::~Video()
{
}

bool Video::capture(const string &video_path)
{
	VideoCapture capture(video_path);
	if (!capture.isOpened()) {
		return false;
	}

	fps = capture.get(CAP_PROP_FPS);
	wSize = windowSize(capture.get(CAP_PROP_FRAME_WIDTH), capture.get(CAP_PROP_FRAME_HEIGHT));
	fCnt = capture.get(CAP_PROP_FRAME_COUNT);

	Mat frame;
	while (capture.read(frame))
	{
		shared_ptr<Mat> frameP(new Mat);
		frame.copyTo(*frameP);
		frames.push_back(frameP);
	}
	capture.release();

	return true;
}