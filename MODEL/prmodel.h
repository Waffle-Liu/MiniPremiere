#pragma once

#include "..\common\stdafx.h"
#include "..\common\Video.h"

using namespace std;
using namespace cv;

class PrModel
{
private:
	int videoNum;
	vector<shared_ptr<Video>> videoList;

public:	
	PrModel();
	~PrModel();

	void addVideo(const string& video_path);
};
