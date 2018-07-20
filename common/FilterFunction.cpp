#include "stdafx.h"
#include "FilterFunction.h"

void filter_mirror(Mat &frame)
{
	int width = frame.cols;
	int height = frame.rows;

	Mat tmp;
	frame.copyTo(tmp);
	for (int y = 0; y < height; y++)
	{
		uchar* frameP = frame.ptr<uchar>(y);
		uchar* tmpP = tmp.ptr<uchar>(y);
		for (int x = 0; x < width; x++)
		{
			frameP[3 * x] = tmpP[3 * (width - 1 - x)];
			frameP[3 * x + 1] = tmpP[3 * (width - 1 - x) + 1];
			frameP[3 * x + 2] = tmpP[3 * (width - 1 - x) + 2];
		}
	}
}

void filter_rotation(Mat &frame)
{
	int width = frame.cols;
	int height = frame.rows;

	Mat tmp;
	frame.copyTo(tmp);
	for (int y = 0; y < height; y++)
	{
		uchar* frameP = frame.ptr<uchar>(y);
		uchar* tmpP = tmp.ptr<uchar>(height - 1 - y);
		for (int x = 0; x < width; x++)
		{
			frameP[3 * x] = tmpP[3 * x];
			frameP[3 * x + 1] = tmpP[3 * x + 1];
			frameP[3 * x + 2] = tmpP[3 * x + 1];
		}
	}
}

void filter_feather(Mat &frame, double arg)
{

	int width = frame.cols;
	int height = frame.rows;
	int centerX = width >> 1;
	int centerY = height >> 1;

	int maxV = centerX * centerX + centerY * centerY;
	int minV = (int)(maxV * (1 - arg));
	int diff = maxV - minV;
	float ratio = width >height ? (float)height / (float)width : (float)width / (float)height;

	Mat origin;
	frame.copyTo(origin);
	for (int y = 0; y < height; y++)
	{

		uchar* originP = origin.ptr<uchar>(y);
		uchar* frameP = frame.ptr<uchar>(y);
		for (int x = 0; x < width; x++)
		{

			int b = originP[3 * x];
			int g = originP[3 * x + 1];
			int r = originP[3 * x + 2];

			float dx = centerX - x;
			float dy = centerY - y;

			if (width > height) {
				dx = (dx * ratio);
			} else {
				dy = (dy * ratio);
			}

			int dstSq = dx * dx + dy * dy;
			float v = ((float)dstSq / diff) * 255;

			r = (int)(r + v);
			g = (int)(g + v);
			b = (int)(b + v);
			r = (r > 223 ? 223 : (r < 31 ? 31 : r));
			g = (g > 223 ? 223 : (g < 31 ? 31 : g));
			b = (b > 223 ? 223 : (b < 31 ? 31 : b));

			frameP[3 * x] = (uchar)b;
			frameP[3 * x + 1] = (uchar)g;
			frameP[3 * x + 2] = (uchar)r;
		}
	}
}

void filter_fudiao(Mat &frame)
{
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);
	for (int y = 1; y<frame.rows - 1; y++)
	{
		uchar *p0 = tmp.ptr<uchar>(y);
		uchar *p1 = tmp.ptr<uchar>(y + 1);
		uchar *frameP = frame.ptr<uchar>(y);

		for (int x = 1; x<frame.cols - 1; x++)
		{
			for (int i = 0; i<3; i++)
			{
				int tmp0 = p1[3 * (x + 1) + i] - p0[3 * (x - 1) + i] + 128;
				if (tmp0<0)
					frameP[3 * x + i] = 0;
				else if (tmp0>255)
					frameP[3 * x + i] = 255;
				else
					frameP[3 * x + i] = tmp0;
			}
		}
	}
}

void filter_diaoke(Mat &frame)
{
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);

	for (int y = 1; y<frame.rows - 1; y++)
	{
		uchar *p0 = tmp.ptr<uchar>(y);
		uchar *p1 = tmp.ptr<uchar>(y + 1);
		uchar *frameP = frame.ptr<uchar>(y);

		for (int x = 1; x<frame.cols - 1; x++)
		{
			for (int i = 0; i<3; i++)
			{
				int tmp1 = p0[3 * (x - 1) + i] - p1[3 * (x + 1) + i] + 128;
				if (tmp1<0)
					frameP[3 * x + i] = 0;
				else if (tmp1>255)
					frameP[3 * x + i] = 255;
				else
					frameP[3 * x + i] = tmp1;
			}
		}
	}
}

void filter_kuozhang(Mat &frame)
{
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);
	int width = frame.cols;
	int height = frame.rows;
	Point center(width / 2, height / 2);

	int R1 = sqrtf(width*width + height * height) / 2;

	for (int y = 0; y<height; y++)
	{
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			int dis = norm(Point(x, y) - center);
			if (dis<R1)
			{
				int newX = (x - center.x)*dis / R1 + center.x;
				int newY = (y - center.y)*dis / R1 + center.y;

				frameP[3 * x] = tmp.at<uchar>(newY, newX * 3);
				frameP[3 * x + 1] = tmp.at<uchar>(newY, newX * 3 + 1);
				frameP[3 * x + 2] = tmp.at<uchar>(newY, newX * 3 + 2);
			}
		}
	}
}

void filter_jiya(Mat &frame)
{
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);
	int width = frame.cols;
	int height = frame.rows;
	Point center(width / 2, height / 2);

	for (int y = 0; y<height; y++)
	{
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			double theta = atan2((double)(y - center.y), (double)(x - center.x));//使用atan出现问题~  

			int R2 = sqrtf(norm(Point(x, y) - center)) * 8; //直接关系到挤压的力度，与R2成反比;              
			int newX = center.x + (int)(R2*cos(theta));
			int newY = center.y + (int)(R2*sin(theta));

			if (newX<0) newX = 0;
			else if (newX >= width) newX = width - 1;
			if (newY<0) newY = 0;
			else if (newY >= height) newY = height - 1;

			frameP[3 * x] = tmp.at<uchar>(newY, newX * 3);
			frameP[3 * x + 1] = tmp.at<uchar>(newY, newX * 3 + 1);
			frameP[3 * x + 2] = tmp.at<uchar>(newY, newX * 3 + 2);
		}
	}
}

void filter_bolang(Mat &frame)
{
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);
	int width = frame.cols;
	int height = frame.rows;
	double angle = 0.0;
	int deltaI = 10;	//波浪周期;
	int A = 10;		//波浪振幅;

	Mat src, img;

	for (int y = 0; y<height; y++)
	{
		int changeX = A * sin(angle);
		uchar *tmpP = tmp.ptr<uchar>(y);
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			if (changeX + x<width && changeX + x>0)		//正弦分布（-1,1）
			{
				frameP[3 * x] = tmpP[3 * (x + changeX)];
				frameP[3 * x + 1] = tmpP[3 * (x + changeX) + 1];
				frameP[3 * x + 2] = tmpP[3 * (x + changeX) + 2];
			}
			//每行开始和结束的空白区;
			else if (x <= changeX)
			{
				frameP[3 * x] = tmpP[0];
				frameP[3 * x + 1] = tmpP[1];
				frameP[3 * x + 2] = tmpP[2];
			} else if (x >= width - changeX)
			{
				frameP[3 * x] = tmpP[3 * (width - 1)];
				frameP[3 * x + 1] = tmpP[3 * (width - 1) + 1];
				frameP[3 * x + 2] = tmpP[3 * (width - 1) + 2];
			}
		}
		angle += ((double)deltaI) / 100;
	}
}

void filter_jingxiangsuofang(Mat &frame, int num)
{
	Mat src1u[3];
	split(frame, src1u);

	int width = frame.cols;
	int height = frame.rows;
	Mat tmp;
	frame.copyTo(tmp);
	Point center(width / 2, height / 2);

	for (int y = 0; y<height; y++)
	{
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			int R = norm(Point(x, y) - center);
			double angle = atan2((double)(y - center.y), (double)(x - center.x));
			int tmp0 = 0, tmp1 = 0, tmp2 = 0;

			for (int i = 0; i<num; i++)
			{
				int tmpR = (R - i)>0 ? (R - i) : 0;
				int newX = tmpR * cos(angle) + center.x;
				int newY = tmpR * sin(angle) + center.y;

				if (newX<0)newX = 0;
				if (newX>width - 1)newX = width - 1;
				if (newY<0)newY = 0;
				if (newY>height - 1)newY = height - 1;

				tmp0 += src1u[0].at<uchar>(newY, newX);
				tmp1 += src1u[1].at<uchar>(newY, newX);
				tmp2 += src1u[2].at<uchar>(newY, newX);
			}

			frameP[3 * x] = (uchar)(tmp0 / num);
			frameP[3 * x + 1] = (uchar)(tmp1 / num);
			frameP[3 * x + 2] = (uchar)(tmp2 / num);
		}
	}
}

void filter_jingxiangxuanzhuan(Mat &frame, int num)
{
	Mat src1u[3];
	split(frame, src1u);

	int width = frame.cols;
	int height = frame.rows;
	Mat tmp;
	frame.copyTo(tmp);
	Point center(width / 2, height / 2);

	for (int y = 0; y<height; y++)
	{
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			int R = norm(Point(x, y) - center);
			double angle = atan2((double)(y - center.y), (double)(x - center.x));
			int tmp0 = 0, tmp1 = 0, tmp2 = 0;
			for (int i = 0; i<num; i++)
			{
				angle += 0.01;
				int newX = R * cos(angle) + center.x;
				int newY = R * sin(angle) + center.y;
				if (newX<0)newX = 0;
				if (newX>width - 1)newX = width - 1;
				if (newY<0)newY = 0;
				if (newY>height - 1)newY = height - 1;

				tmp0 += src1u[0].at<uchar>(newY, newX);
				tmp1 += src1u[1].at<uchar>(newY, newX);
				tmp2 += src1u[2].at<uchar>(newY, newX);
			}

			frameP[3 * x] = (uchar)(tmp0 / num);
			frameP[3 * x + 1] = (uchar)(tmp1 / num);
			frameP[3 * x + 2] = (uchar)(tmp2 / num);
		}
	}
}

void filter_feng(Mat &frame, int num)
{
	int num1 = 2 * num;//	num1：风线长度

	Mat src1u[3];
	split(frame, src1u);
	int width = frame.cols;
	int height = frame.rows;
	Point center(width / 2, height / 2);
	RNG rng;

	for (int y = 0; y<height; y++)
	{
		uchar *frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			for (int i = 0; i<num; i++)		//	num：风线密度
			{
				int newX = rng.uniform(i*width / num, (i + 1)*width / num);
				int newY = y;

				if (newX<0) newX = 0;
				if (newX>width - 1) newX = width - 1;

				uchar tmp0 = src1u[0].at<uchar>(newY, newX);
				uchar tmp1 = src1u[1].at<uchar>(newY, newX);
				uchar tmp2 = src1u[2].at<uchar>(newY, newX);

				for (int j = 0; j<num1; j++)	//num1：风线长度
				{
					int tmpX = newX - j;//减：风向左；加：风向右

					if (tmpX<0) tmpX = 0;
					if (tmpX>width - 1) tmpX = width - 1;

					frameP[tmpX * 3] = tmp0;
					frameP[tmpX * 3 + 1] = tmp1;
					frameP[tmpX * 3 + 2] = tmp2;
				}
			}
		}
	}
}

void filter_xuanwo(Mat &frame, double Para)
{
	double Pi = 3.14;

	int height = frame.rows;
	int width = frame.cols;
	Point center(width / 2, height / 2);

	Mat src1u[3];
	split(frame, src1u);

	for (int y = 0; y<height; y++)
	{
		uchar* frameP = frame.ptr<uchar>(y);
		uchar* srcP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			int R = norm(Point(x, y) - center);
			double angle = atan2((double)(y - center.y), (double)(x - center.x));
			double delta = Pi * Para / sqrtf(R + 1);
			int newX = R * cos(angle + delta) + center.x;
			int newY = R * sin(angle + delta) + center.y;

			if (newX<0) newX = 0;
			if (newX>width - 1) newX = width - 1;
			if (newY<0) newY = 0;
			if (newY>height - 1) newY = height - 1;
			frameP[3 * x] = src1u[0].at<uchar>(newY, newX);
			frameP[3 * x + 1] = src1u[1].at<uchar>(newY, newX);
			frameP[3 * x + 2] = src1u[2].at<uchar>(newY, newX);
		}
	}
}

void filter_sumiao(Mat &frame)
{
	int width = frame.cols;
	int heigh = frame.rows;
	Mat gray0, gray1;
	//去色
	cvtColor(frame, gray0, CV_BGR2GRAY);
	//反色
	addWeighted(gray0, -1, NULL, 0, 255, gray1);
	//高斯模糊,高斯核的Size与最后的效果有关
	GaussianBlur(gray1, gray1, Size(11, 11), 0);
	//融合：颜色减淡

	for (int y = 0; y<heigh; y++)
	{
		uchar* P0 = gray0.ptr<uchar>(y);
		uchar* P1 = gray1.ptr<uchar>(y);
		uchar* frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			int tmp0 = P0[x];
			int tmp1 = P1[x];
			frameP[3 * x] = frameP[3 * x + 1] = frameP[3 * x + 2] = (uchar)min((tmp0 + (tmp0*tmp1) / (256 - tmp1)), 255);
		}
	}
}

void filter_huaijiu(Mat &frame)
{
	int width = frame.cols;
	int height = frame.rows;
	RNG rng;
	Mat tmp(frame.size(), CV_8UC3);
	frame.copyTo(tmp);

	for (int y = 0; y<height; y++)
	{
		uchar* P0 = tmp.ptr<uchar>(y);
		uchar* frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			float B = P0[3 * x];
			float G = P0[3 * x + 1];
			float R = P0[3 * x + 2];
			float newB = 0.272*R + 0.534*G + 0.131*B;
			float newG = 0.349*R + 0.686*G + 0.168*B;
			float newR = 0.393*R + 0.769*G + 0.189*B;

			if (newB<0)newB = 0;
			if (newB>255)newB = 255;
			if (newG<0)newG = 0;
			if (newG>255)newG = 255;
			if (newR<0)newR = 0;
			if (newR>255)newR = 255;

			frameP[3 * x] = (uchar)newB;
			frameP[3 * x + 1] = (uchar)newG;
			frameP[3 * x + 2] = (uchar)newR;
		}
	}
}

void filter_qiangguang(Mat &frame)
{
	int R = 11;
	int width = frame.cols;
	int height = frame.rows;
	Mat img;
	frame.copyTo(img);

	float tmp, r;
	for (int y = 0; y<height; y++)
	{
		uchar* imgP = img.ptr<uchar>(y);
		uchar* frameP = frame.ptr<uchar>(y);
		for (int x = 0; x<width; x++)
		{
			r = (float)imgP[3 * x];
			if (r>127.5)
				tmp = r + (255 - r)*(r - 127.5) / 127.5;
			else
				tmp = r * r / 127.5;
			tmp = tmp>255 ? 255 : tmp;
			tmp = tmp<0 ? 0 : tmp;
			frameP[3 * x] = (uchar)(tmp);
			r = (float)imgP[3 * x + 1];
			if (r>127.5)
				tmp = r + (255 - r)*(r - 127.5) / 127.5;
			else
				tmp = r * r / 127.5;
			tmp = tmp>255 ? 255 : tmp;
			tmp = tmp<0 ? 0 : tmp;
			frameP[3 * x + 1] = (uchar)(tmp);
			r = (float)imgP[3 * x + 2];
			if (r>127.5)
				tmp = r + (255 - r)*(r - 127.5) / 127.5;
			else
				tmp = r * r / 127.5;
			tmp = tmp>255 ? 255 : tmp;
			tmp = tmp<0 ? 0 : tmp;
			frameP[3 * x + 2] = (uchar)(tmp);
		}
	}
}