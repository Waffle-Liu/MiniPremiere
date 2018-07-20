#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "../common/stdafx.h"
#include "../common/FilterFunction.h"
#include "../common/Function.h"
#include "../common/windowSize.h"
#include "../common/etlbase.h"

#define NIL -1

using namespace std;
using namespace cv;

typedef vector<Mat> VideoFrames;

class PrModel: public Proxy_PropertyNotification<PrModel>, public Proxy_CommandNotification<PrModel>
{
protected:
	int fCnt;  // frames count
	double fps;  // frames per second
	windowSize wSize;
	VideoFrames frames;  // frames list
	//	modify
	// VideoCapture vCapture;

public:
	PrModel();
	PrModel(const string&);  // PrModel(video_path): Capture the video at the destination path.
	PrModel(const PrModel&, int, int);  // PrModel(old_video, start_frame, end_frame): Copy part of another video.
	~PrModel();
	void capture(const string&);  // this->capture(video_path): Capture the video at the destination path.
	void writer(const string&, int = NIL, int = NIL);  // this->(video_path, start_frame, end_frame, fps, wSize);

	void play();

	double getFPS() const;
	double getWidth() const;
	double getHeight() const;
	int getFrameCnt() const;
	//	Mat getFrame(int = 0);

	void cut(int, int);  // this->cut(start_frame, end_frame): Cut this video.
	void link(const PrModel&, int = NIL);  // this->link(next_video): Link the next video to the end.
	void addSubtitle(const string&, int, int, double, double, int, double, double, double);
	void addFilter(int, int = NIL, int = NIL);
	void changeSpeed(double speed);

	void addSticker(const string &imagename, int x, int y, int start_frame, int end_frame);

	friend PrModel cut(const PrModel&, int, int);  // cut(start_frame, end_frame): Return a video pointer with a video from start_frame to end_frame.
	friend PrModel link(const PrModel&, const PrModel&, int);
};

#endif 