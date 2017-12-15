#-------------------------------------------------
#
# Project created by QtCreator 2015-12-26T21:15:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets winextras

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    2048.cpp

HEADERS  += mainwindow.h \
    head.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    myapp.rc
RC_FILE = myapp.rc
