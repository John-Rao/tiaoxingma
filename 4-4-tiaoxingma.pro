#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T02:36:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4-4-tiaoxingma
TEMPLATE = app


INCLUDEPATH+=E:\CVforQt\include\opencv\
E:\CVforQt\include\opencv2\
E:\CVforQt\include

LIBS += -L  E:/CVforQt/lib/libopencv_*.a

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        dialog.cpp \
    videoio.cpp \
    videostream.cpp \
    posmatch.cpp \
    analyzer.cpp

HEADERS  += dialog.h \
    videoio.h \
    videostream.h \
    posmatch.h \
    analyzer.h
