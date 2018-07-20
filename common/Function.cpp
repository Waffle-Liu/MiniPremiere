#include "stdafx.h"
#include "Function.h"

using namespace std;
string num2str(int num)
{
	stringstream s;
	string snum;
	s << num;
	s >> snum;
	return snum;
}

int progress(int start, int end, int now)
{
	int percent = (int)((double)(now + 1 - start) / (double)(end - start) * 100);
	return percent;
}