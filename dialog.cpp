#include "dialog.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    videoWindow=new QLabel();
    videoWindow->setMinimumSize(640,480);
    startBtn=new QPushButton("start");
    showBtn=new QPushButton("show");
    showBtn->setVisible(false);
    continueBtn=new QPushButton("continue");
    continueBtn->setDisabled(true);
    lineEdit=new QLineEdit();
    rightLayout=new QVBoxLayout();
    mainLayout=new QHBoxLayout(this);

    rightLayout->addWidget(startBtn);
    rightLayout->addWidget(showBtn);
    rightLayout->addWidget(continueBtn);
    rightLayout->addStretch();
    rightLayout->addWidget(lineEdit);
    mainLayout->addWidget(videoWindow);
    mainLayout->addLayout(rightLayout);

    stream=new VideoStream();
    timer=new QTimer();


    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(StartCap()));
    connect(showBtn,SIGNAL(clicked(bool)),this,SLOT(test()));
    connect(continueBtn,SIGNAL(clicked(bool)),this,SLOT(continueEve()));
    connect(timer,SIGNAL(timeout()),this,SLOT(showVideo()));
    connect(stream,SIGNAL(getStr(QString)),this,SLOT(showRes(QString)));
    connect(this,SIGNAL(startCacu()),stream,SLOT(setStart()));

}

Dialog::~Dialog()
{
    qDebug()<<"1231";
    timer->stop();
    stream->terminate();
    delete stream;
}

void Dialog::showVideo()
{
    Mat mat;
    stream->GetStream().copyTo(mat);
    cvtColor(mat,mat,CV_BGR2RGB);
    Img=new QImage(mat.data,mat.cols,mat.rows,QImage::Format_RGB888);
    videoWindow->setPixmap(QPixmap::fromImage(*Img));
    delete Img;

}

void Dialog::test()
{
    Mat mat;
    stream->test().copyTo(mat);
    imshow("12111",mat);
}

void Dialog::showRes(QString res)
{
    lineEdit->setText(res);
    timer->stop();
    continueBtn->setEnabled(true);
}

void Dialog::continueEve()
{

    continueBtn->setDisabled(true);
    emit startCacu();
    timer->start(30);
}


void Dialog::StartCap()
{
    stream->OpenCap();
    stream->start();
    timer->start(30);
    startBtn->setDisabled(true);
}
