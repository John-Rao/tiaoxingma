#include "videoio.h"

VideoIO::VideoIO()
{

}

void VideoIO::OpenCap()
{
    cap=VideoCapture(1);

}

void VideoIO::CloseCap()
{
    cap.release();
}

void VideoIO::GetImg(Mat *mat)
{
    bool bSuccess = cap.read(*mat);
    if (!bSuccess)
    {
        qDebug() << "Cannot read a frame from video stream" << "\n";
    }
}
