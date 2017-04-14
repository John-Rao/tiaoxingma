#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <videoio.h>
#include <videostream.h>
#include <QTimer>
#include <QEvent>
#include <opencv2/opencv.hpp>
#include <QLineEdit>
#include <QThread>
using namespace cv;



class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QLabel *videoWindow;
    QImage *Img;
    QPushButton *startBtn;
    QPushButton *showBtn;
    QPushButton *continueBtn;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    VideoStream *stream;
    QTimer *timer;
    QLineEdit *lineEdit;

signals:
    void startCacu();
public slots:
    void StartCap();
    void showVideo();
    void test();
    void showRes(QString res);
    void continueEve();
protected:
};

#endif // DIALOG_H
