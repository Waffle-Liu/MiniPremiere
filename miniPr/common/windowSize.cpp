#include "stdafx.h"
#include "windowSize.h"

windowSize::windowSize(double w, double h)
{
	width = w;
	height = h;
}

windowSize::~windowSize()
{
}

bool windowSize::operator==(windowSize csize)
{
	if (width == csize.width && height == csize.height) {
		return true;
	} else {
		return false;
	}
}