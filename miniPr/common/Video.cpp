#include "Video.h"

using namespace std;
using namespace cv;

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

void Video::play()
{
	int slidp = 0;

	namedWindow("display", CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("framenum", "display", &slidp, fCnt);

	for (int i = 0; i < fCnt; i++)
	{
		bool isEscape = false;
		setTrackbarPos("framenum", "display", slidp);
		imshow("display", *frames[i]);
		slidp++;

		switch (waitKey((double)1000 / fps)) {
		case 32:
			switch (waitKey()) {
			case 27:
				isEscape = true;
				break;
			default:
				break;
			}
			break;
		case 27:
			isEscape = true;
			break;
		}

		if (isEscape) break;
	}
	cvDestroyWindow("display");
}

bool Video::cut(int start_frame, int end_frame)
{
	if (start_frame > fCnt) {
		return false;
	}

	frames.erase(frames.begin(), frames.begin() + start_frame);
	frames.erase(frames.begin() + (end_frame - start_frame), frames.end());
	fCnt = end_frame - start_frame;
	return true;
}

bool Video::changeSpeed(double rate)
{
	if (rate < 1) {
		fps = fps * rate;
	} else {
		fCnt = (int)(double(fCnt) / rate);
		for (int i = 0; i < fCnt; i++)
		{
			frames[i] = frames[(int)(i * rate)];
		}
	}
	return true;
}