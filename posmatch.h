#ifndef POSMATCH_H
#define POSMATCH_H
#include <QThread>
#include <opencv2/opencv.hpp>
using namespace cv;

class PosMatch : public QThread
{
    Q_OBJECT
public:
    PosMatch();
    void setMat(Mat *mat);
    Rect getPos();
    Mat *testMat;

private:
    Mat *srcImg;
    Rect posRect;

protected:
    void run();
signals:
    void analy(Mat);
};

#endif // POSMATCH_H
