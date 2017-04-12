#include "posmatch.h"
#include <QDebug>
#include <vector>

PosMatch::PosMatch()
{
    testMat=new Mat();
    posRect=Rect(0,0,0,0);
}

void PosMatch::setMat(Mat *mat)
{
    srcImg=mat;
}

Rect PosMatch::getPos()
{
    return posRect;
}

void PosMatch::run()
{
    Mat kernal=getStructuringElement(MORPH_RECT,Size(25,5));
    Mat edKl=getStructuringElement(MORPH_RECT,Size(3,3));
    std::vector<std::vector<Point>> contours;
    Rect maxRe;
    while(1){
        Mat Img;
        Mat gradX;
        Mat threshImg;
        srcImg->copyTo(Img);
        int index=0;
        double maxSize=0.0;
        contours.clear();
        cvtColor(Img,Img,CV_BGR2GRAY,CV_8UC1);
        Scharr(Img,gradX,CV_16S,1,0);
        convertScaleAbs(gradX,gradX);
        blur(gradX,gradX,Size(5,5));
        threshold(gradX,threshImg,200,255,CV_8UC1);
        morphologyEx(threshImg,threshImg,MORPH_CLOSE,kernal);
        erode(threshImg,threshImg,edKl,Point(-1,-1),8);
        dilate(threshImg,threshImg,edKl,Point(-1,-1),15);
        //轮廓
        findContours(threshImg,contours,RETR_LIST,CHAIN_APPROX_NONE);
        for(unsigned int i=0;i<contours.size();i++){
            if(maxSize<contourArea(contours[i])){
                maxSize=contourArea(contours[i]);
                index=i;
            }
        }
        if(contours.size()>0){
            maxRe=boundingRect(contours[index]);
            rectangle(threshImg,maxRe,Scalar(155));
            posRect=maxRe;
            (*srcImg)(posRect).copyTo(*testMat);
            emit analy(*testMat);
        }else{
            posRect=Rect(0,0,0,0);
        }
        msleep(500);
    }
}
