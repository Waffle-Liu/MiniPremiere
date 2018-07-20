#pragma once

#include "stdafx.h"
using namespace cv;

void filter_mirror(Mat &frame);//0
void filter_rotation(Mat &frame);//1
void filter_feather(Mat &frame, double);//2
void filter_fudiao(Mat &frame);//3	filter
void filter_diaoke(Mat &frame);//4  f
void filter_kuozhang(Mat &frame);//5  special
void filter_jiya(Mat &frame);//6   s
void filter_bolang(Mat &frame);//7    s
void filter_jingxiangsuofang(Mat &frame, int);//8    tansaction
void filter_jingxiangxuanzhuan(Mat &frame, int);//9    t
void filter_feng(Mat &frame, int);//10    t
void filter_xuanwo(Mat &frame, double);//11    t
void filter_sumiao(Mat &frame);//12   f
void filter_huaijiu(Mat &frame);//13   f
void filter_qiangguang(Mat &frame);//14   f
