#ifndef VIDEOIO_H
#define VIDEOIO_H
#include <QDebug>
#include <opencv2/opencv.hpp>
using namespace cv;


class VideoIO
{
public:
    VideoIO();
public:
    void OpenCap();
    void CloseCap();
    void GetImg(Mat *mat);
private:
    VideoCapture cap;

};

#endif // VIDEOIO_H
