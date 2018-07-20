#pragma once

#include "stdafx.h"
#define nullSize windowSize(-1, -1)

struct windowSize {
public:
	double width;
	double height;

	windowSize(double w = -1, double h = -1);
	~windowSize();

	bool operator==(windowSize csize);
};
