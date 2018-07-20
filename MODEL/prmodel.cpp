#include "prmodel.h"

PrModel::PrModel()
{
}

PrModel::PrModel(const string & video_path)
{
    this->capture(video_path);
    cout << ">> Video imported sucessful. (Path: " << video_path << ")" << endl;
}

PrModel::PrModel(const PrModel &old_video, int start_frame, int end_frame) : PrModel(old_video)
{
    this->cut(start_frame, end_frame);
    cout << ">> PrModel imported sucessful." << endl;
}

PrModel::~PrModel()
{
}

double PrModel::getFPS() const
{
    return fps;
}

double PrModel::getWidth() const
{
    return wSize.width;
}

double PrModel::getHeight() const
{
    return wSize.height;
}

int PrModel::getFrameCnt() const
{
    return fCnt;
}

void PrModel::capture(const string &video_path)
{
    VideoCapture capture(video_path);
    if (!capture.isOpened()) {
        cout << ">> [Error] Failed to import the video!" << endl;
        return;
    }

    fps = capture.get(CAP_PROP_FPS);
    wSize = windowSize(capture.get(CAP_PROP_FRAME_WIDTH), capture.get(CAP_PROP_FRAME_HEIGHT));
    fCnt = capture.get(CAP_PROP_FRAME_COUNT);

    Mat frame;
    while (capture.read(frame))
    {
        Mat *frameP = new Mat;
        frame.copyTo(*frameP);
        frames.push_back(*frameP);
    }

    capture.release();
    cout << ">> PrModel imported sucessful. (Path: " << video_path << ")" << endl;
}

void PrModel::cut(int start_frame, int end_frame)
{
    frames.erase(frames.begin(), frames.begin() + start_frame);
    frames.erase(frames.begin() + (end_frame - start_frame), frames.end());
    fCnt = end_frame - start_frame;
}


PrModel cut(const PrModel &old_video, int start_frame, int end_frame)
{
    PrModel video(old_video);
    video.cut(start_frame, end_frame);
    return video;
}

void PrModel::link(const PrModel &video, int trans_mode)
{

    if (wSize.width < video.wSize.width) {
        wSize.width = video.wSize.width;
    }
    if (wSize.height < video.wSize.height) {
        wSize.height = video.wSize.height;
    }
    if (fps != video.fps) {
        cout << ">> [Warning] Trying to stitch video with different FPS." << endl;
    }

    int trans_begin = fCnt - (fCnt < 10 ? fCnt : 10);
    int trans_end = fCnt + (video.fCnt < 10 ? video.fCnt : 10);

    cout << ">> Video linking ..." << endl;
    frames.insert(frames.end(), video.frames.begin(), video.frames.end());
    fCnt += video.fCnt;
    cout << ">> Video linked sucessful." << endl;

    if(trans_mode != NIL)
    {
        cout << ">> Transition effect adding ..." << endl;
        this->addFilter(trans_mode, trans_begin, trans_end);
        cout << ">> Video linked sucessful." << endl;
    }
}

PrModel link(const PrModel &video_1, const PrModel &video_2, int trans_mode)
{
    PrModel video(video_1);
    video.link(video_2, trans_mode);
    return video;
}

void PrModel::play()
{
    int slidp = 0;
    namedWindow("display", CV_WINDOW_AUTOSIZE);
    cvCreateTrackbar("framenum", "display", &slidp, fCnt);

    for (int i = 0; i < fCnt; i++)
    {
        bool isEscape = false;
        setTrackbarPos("framenum", "display", slidp);
        imshow("display", frames[i]);
        slidp++;

        switch (waitKey((double)1000 / fps))
        {
        case 32:
            switch (waitKey())
            {
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
}

void PrModel::changeSpeed(double speed)
{
    cout << ">> Changing speed ... " << endl;

    if (speed < 1) {
        fps = fps * speed;
    } else {
        fCnt = (int)(double(fCnt) / speed);
        for (int i = 0; i < fCnt; i++)
        {
            frames[i] = frames[(int)(i * speed)];
            progress(0, fCnt, i);
        }
    }

    cout << ">> Speed changed sucessful." << endl;
}

void PrModel::addSticker(const string& imagename, int pos_x, int pos_y, int start_frame, int end_frame)
{
    Mat image = imread(imagename);

    for (int i = start_frame; i < end_frame; i++)
    {
        int width, height;
        if (frames[i].rows < image.rows + pos_y) {
            height = frames[i].rows - pos_y;
        } else {
            height = image.rows;
        }

        if (frames[i].cols < image.cols + pos_x) {
            width = frames[i].cols - pos_x;
        } else {
            width = image.cols;
        }

        for (int y = 0; y < height; y++)
        {
            uchar* bkgP = frames[i].ptr<uchar>(y);
            uchar* imgP = image.ptr<uchar>(y);
            for (int x = 0; x < width; x++)
            {
                bkgP[3 * (x + pos_x)] = imgP[3 * x];
                bkgP[3 * (x + pos_x) + 1] = imgP[3 * x + 1];
                bkgP[3 * (x + pos_x) + 2] = imgP[3 * x + 2];
            }
        }
    }
}

void PrModel::addFilter(int mode, int start_frame, int end_frame)
{

    if (start_frame == NIL) {
        start_frame = 0;
    }
    if (end_frame == NIL) {
        end_frame = fCnt;
    }

    cout << ">> Filter adding ... " << endl;
    for (int i = start_frame; i < end_frame; i++)
    {
        double p = (double)progress(start_frame, end_frame, i) / 100;
        double arg = (0.5 - fabs(p - 0.5)) * 2;
        switch (mode) {
        case 0:
            filter_mirror(frames[i]);
            break;
        case 1:
            filter_rotation(frames[i]);
            break;
        case 2:
            filter_feather(frames[i], 1 - arg);
            break;
        case 3:
            filter_fudiao(frames[i]);
            break;
        case 4:
            filter_diaoke(frames[i]);
            break;
        case 5:
            filter_kuozhang(frames[i]);
            break;
        case 6:
            filter_jiya(frames[i]);
            break;
        case 7:
            filter_bolang(frames[i]);
            break;
        case 8:
            filter_jingxiangsuofang(frames[i], (int)(arg * 40) + 1);
            break;
        case 9:
            filter_jingxiangxuanzhuan(frames[i], (int)(arg * 40) + 1);
            break;
        case 10:
            filter_feng(frames[i], (int)(arg * 20) + 1);
            break;
        case 11:
            filter_xuanwo(frames[i], arg * 20);
            break;
        case 12:
            filter_sumiao(frames[i]);
            break;
        case 13:
            filter_huaijiu(frames[i]);
            break;
        case 14:
            filter_qiangguang(frames[i]);
            break;
        default:
            break;
        }
        progress(start_frame, end_frame, i);
    }

    cout << ">> Filter added sucessfully." << endl;
}

void PrModel::addSubtitle(const string &text, int start_frame, int end_frame, double x, double y, int fontSize, double r, double g, double b)
{
    if (start_frame > fCnt) {
        cout << ">> [Warning] Wrong start time!" << endl;
        return;
    } else if (end_frame > fCnt) {
        cout << ">> [Warning] Wrong end time." << endl;
        end_frame = fCnt;
    }

    cout << ">> Adding subtitle ... " << endl;

    for (int i = start_frame; i < end_frame; i++)
    {
        putText(frames[i], text, Point(x, y), FONT_HERSHEY_COMPLEX, fontSize, Scalar(r, g, b), 2, 8, 0);
        progress(start_frame, end_frame, i);
    }

    cout << ">> Subtitle added sucessful." << endl;
}

void PrModel::writer(const string &video_path, int start_frame, int end_frame)
{
    if (start_frame == NIL) {
        start_frame = 0;
    }
    if (end_frame == NIL) {
        end_frame = fCnt;
    }

    if (start_frame > fCnt) {
        cout << ">> [Error] Unavailable start time!" << endl;
        return;
    } else if (end_frame > fCnt) {
        cout << ">> [Warning] Wrong end time." << endl;
        end_frame = fCnt;
    }

    cout << ">> Video exporting ..." << endl;

    VideoWriter writer(video_path, CV_FOURCC('M', 'J', 'P', 'G'), fps, Size(wSize.width, wSize.height));
    for (int i = start_frame; i < end_frame; i++)
    {
        writer.write(frames[i]);
        progress(start_frame, end_frame, i);
    }
    writer.release();

    cout << ">> Video exported sucessful. (Path: " << video_path << ")" << endl;
}