#ifndef ANALYZER_H
#define ANALYZER_H
#include <opencv2/opencv.hpp>
#include <QObject>

#include <QString>
using namespace cv;

class classis{
public:
    classis(int pos,int wid){
        this->pos=pos;
        this->wid=wid;
    }
public:
    int pos;
    int wid;
};
class Analyzer:public QObject
{
    Q_OBJECT
public:
    Analyzer();
    void ImgtoNum();
    void getSize(int startPos,int width,Mat Img_2zhi,std::vector<classis> *blackBar,std::vector<classis> *whiteBar);
    void cacuDig(std::vector<classis> blackBar, std::vector<classis> whiteBar, int result[]);
    bool checkOut(int result[]);
private:
    Mat rawImg;

public slots:
    void receiveImg(Mat rawImg);
signals:
    void successGet(QString);
};

#endif // ANALYZER_H
